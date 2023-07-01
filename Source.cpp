#include <iostream>     //for using input output function
#include <cmath>        //for using complex mathematical operations
#include <iomanip>      //for manipulation of the output
using namespace std;
//start of the program
int main()
{    //declaring constants for the equations
	const double density(1000);
	const double acc(9.81);
	//declaring input variable used in the equation
	double a, b, d, D, z, d1, d2, stepsize, x;
	//declaring output variable used in the equation 
	double force;


	int choice;

	do {
		//printing instructions/main menu for the user
		cout << "Enter 1 to determine the force on the dam" << endl;
		cout << "Enter 2 to determine the force for a range of water elevations" << endl;
		cout << "Enter 3 for quitting the program" << endl;
		cout << "Your choice is: " << endl;

		cin >> choice; //reading in the integer input for the choice
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		switch (choice) //to perform different action based on the choice
		{
		case 1: //to allow the user to calculate the force on the dam
			cout << "Enter the total depth of the channel in meters" << endl;
			cin >> D;
			/*prevents error in case wrong data type is entered and if negative
			value is entered for the total depth, prompts user to re-enter the value*/
			while (cin.fail() || D < 0)
			{
				cin.clear();
				cin.ignore();
				cout << "Error! Enter a non negative and non zero digit value for D" << endl;
				cin >> D;
			}

			cout << "Enter the width of the channel base in meters" << endl;
			cin >> b;
			/*prevents error in case wrong data type is entered and if negative
			value is entered for the width, prompts user to re-enter the value*/
			while (cin.fail() || b < 0)
			{
				cin.clear();
				cin.ignore();
				cout << "Error! Enter a valid value for the width" << endl;
				cin >> b;
			}

			cout << "Enter the elevation of the water above the channel bottom in meters" << endl;
			cin >> d;
			/*prevents error in case wrong data type is entered
			and if negative value is entered for the elevation of
			water, prompts user to re-enter the value*/
			while (cin.fail() || d < 0 || d > D)
			{
				cin.clear();
				cin.ignore();
				cout << "Error! Enter a valid value for the elevation" << endl;
				cin >> d;
			}

			cout << "Enter the distance from the edge of the channel in meters" << endl;
			cin >> a;
			/*prevents error in case wrong data type is entered and
			if negative value is entered for the distance from the
			edge, prompts user to re-enter the value*/
			while (cin.fail() || a < 0)
			{
				cin.clear();
				cin.ignore();
				cout << "Error! Please enter a valid value for the distance" << endl;
				cin >> a;
			}
			//expression to evaluate the force on the dam using all the inputs
			force = density * acc * (((a * pow(d, 4)) / (6 * pow(D, 2)) + ((b * pow(d, 2)) / 2)));
			//prints the output on the screen in 8 digits
			cout << setprecision(20) << "The value of the force is: " << force << " N " << endl;
			break; //to terminate the statement sequence
		case 2: // to allow the user to calculate the force over a range of elevations

			cout << "Enter the total depth of the channel in meters" << endl;
			cin >> D;
			/*prevents error in case wrong data type is entered
			and if negative value is entered for the depth of the channel
			, prompts user to re-enter the value*/
			while (cin.fail() || D < 0)
			{
				cin.clear();
				cin.ignore();
				cout << "Error! Enter a non negative and non zero digit value for D" << endl;
				cin >> D;
			}

			cout << "Enter the width of the channel base in meters" << endl;
			cin >> b;
			/*prevents error in case wrong data type is entered
			and if negative value is entered for the width of
			the channel base, prompts user to re-enter the value*/
			while (cin.fail() || b < 0)
			{
				cin.clear();
				cin.ignore();
				cout << "Error! Enter a valid value for the width" << endl;
				cin >> b;
			}

			cout << "Enter the distance from the edge of the channel in meters" << endl;
			cin >> a;
			/*prevents error in case wrong data type is entered
			and if negative value is entered for the distance from
			the edge of the channel, prompts user to re-enter the value*/
			while (cin.fail() || a < 0)
			{
				cin.clear();
				cin.ignore();
				cout << "Error! Please enter a valid value for the distance" << endl;
				cin >> a;
			}

			cout << "Enter the maximum elevation in meters" << endl;
			cin >> d1;
			/*prevents error in case wrong data type is entered,
			if negative value is entered or if the maximum elevation
			is greater than the total depth of the dam for the maximum elevation,
			prompts user to re-enter the value*/
			while (cin.fail() || d1 <= 0 || d1 > D)
			{
				cin.clear();
				cin.ignore();
				cout << "Invalid input for maximum elevation! Please re-enter the correct value. " << endl;
				cin >> d1;
			}
			cout << "Enter the minimum elevation in meters" << endl;
			cin >> d2;
			/*prevents error in case wrong data type is entered,
		   if negative value is entered or if the minimum elevation
		   is greater than the total depth of the dam for the maximum elevation,
		   prompts user to re-enter the value*/
			while (cin.fail() || d2<0 || d2 > D)
			{
				cin.clear();
				cin.ignore();
				cout << "Invalid value for the minimum elevation! Please re-enter the correct value" << endl;
				cin >> d2;
			}

			/*prevents error in case the maximum elevation is
			less than or equal to the minimum elevation,
			prompts user to re-enter the value*/
			while (d1 <= d2)

			{
				cout << "Invalid value for maximum elevation and/or minimum elevation" << endl;
				cout << "Please enter maximum elevation and then the minimum elevation again" << endl;
				cin >> d1 >> d2;
			}

			cout << "Enter the stepsize for the range of elevation" << endl;
			cin >> stepsize;

			/*prevents error in case wrong data type is entered,
		   if negative value or zero is entered or if the step size
		   is greater than the difference between the maximum and
		   minimum elevation,prompts user to re-enter the value*/
			while (cin.fail() || stepsize <= 0 || stepsize > d1 - d2)
			{
				cin.clear();
				cin.ignore();
				cout << "Invalid value for the stepsize, Please enter the step size again" << endl;
				cout << "Make sure your stepsize is less than the range of elevation" << endl;
				cin >> stepsize;

			}

			cout << setw(20) << left << "Elevation/m" << setw(20) << left << "Force/N" << endl; //heading of the table for the output
			for (double x = d2; x <= d1 + 0.01; x += stepsize) //for loop to repeat within the range by adding the step size
			{
				force = density * acc * (a * pow(x, 4) / 6 * pow(D, 2) + (b * pow(x, 2) / 2)); //expression used to find the force exerted
				/*giving the output in a tabular form
				with a 20 unit column width and
			  15 digit precision*/
				cout << setprecision(15) << setw(20) << left << x << left << setprecision(15) << setw(20) << force << endl;
			}
			break;

		case 3: //if the user wants to exit the program 

			cout << "You have successfuly exited the program!" << endl;
			break;

			// if the user inputs some other digit other than the three options
		default: cout << "Select 1, 2 or 3!" << endl;
			break;

		}

	} while (choice != 3); //to exit the program if the user enters 3 only and a loop if it enters 

	system("pause");
	return 0; //end of the program
}