//	Sean Mathews
//  8/30/17
//	CS240-003
//	This Project's objective is to draw rectangles. It takes input of width and height from the user. It also takes two different chararacter choices from user to be used for the rectangle 

#include<iostream>
#include<istream>
using namespace std;

const int MIN_WIDTH = 3;
const int MAX_WIDTH = 60;


const int MAX_HEIGHT = 20;
const int MIN_HEIGHT = 3;

 void drawRectangle(int height, int width, char border, char fill);
 int changeHeight(int newHeight);
 int changeWidth(int sameHeight);

int main()
{
	char menu_choice;
	
	int height = 10;
	int width = 10;
	int border = '*';
	int fill = '#';

	int newHeight = height;
	int newWidth = width;
	char newBorder = border;
	char newFill = fill;

	char Q = 'Q';
	char H = 'H';
	char W = 'W';
	char F = 'F';
	char B = 'B';
	
	char q = 'q';
	char h = 'h';
	char w = 'w';
	char f = 'f';
	char b = 'b';






	cout << "Hello Stranger...Lets draw some Rectangles...\n";
	
	

	// it first draws a 10 by 10 Rectangle
	drawRectangle(height, width, border, fill);

	
	// asks height with an error trap
	//while input isnt q, then do shit. Otherwise display goodbye message
	//is input h or w or f or b or quit? then go on to do shit
	// the algorithim of this may be wrong
	
	do
	{
		cout << "\n";

		cout << "h) Change the height\n";
		cout << "w) Change the width\n";
		cout << "f) Change the fill character\n";
		cout << "b) Change the border character\n";
		cout << "q) Quit\n";
		cout << "Choose one of the options above: \n";

		cin >> menu_choice;

		while  ( !(menu_choice == h || menu_choice == H || menu_choice == w || menu_choice == W || menu_choice == f || menu_choice == F || menu_choice == b || menu_choice == B || menu_choice == q || menu_choice == Q) )
		{
			cout << "I'm sorry you picked a key not listed in the options. \n Please pick a list option \n";
			cin >> menu_choice;
		}
	
		//The huge if statement is representing the options that the user can do

		// Height //
		if (menu_choice == h || menu_choice == H)
		{
			 newHeight = changeHeight(height);
			

			//This uses a do-while because in order to correctly put in error traps it needs to execute the question to the user first everytime before it checks if it was the correct output or not
			
			drawRectangle(newHeight, newWidth, newBorder, newFill);
		}

		// Width //
		else if (menu_choice == w || menu_choice == W)
		{
			
			 newWidth = changeWidth(width);

			drawRectangle(newHeight, newWidth, newBorder, newFill);
		}

		//These dont need need loops because it asks for any character on the keyboard. 


		// Fill //
		else if (menu_choice == f || menu_choice == F)
		{
			cout << "Change the fill character";
			cin >> newFill;

			drawRectangle(newHeight, newWidth, newBorder, newFill);
		}


		// Border //
		else if (menu_choice == b || menu_choice == B)
		{
			cout << "Change the border character";
			cin >> newBorder;

			drawRectangle(newHeight, newWidth, newBorder, newFill);
		}

		else if (menu_choice == q || menu_choice == Q)
		{
			cout << "Thanks for playing..See you around next time ;) \n";

			system("pause");
			return 0;
		}
	} while ( ( (menu_choice == Q) || (menu_choice == H) || (menu_choice == W) || (menu_choice == F) || (menu_choice == B) || (menu_choice == q) || (menu_choice == h) || (menu_choice == w) || (menu_choice == f) || (menu_choice == b) ) );
	
	
}
	
//This function changes the Height and returns the new width back to main//

int changeHeight(int changedHeight)
{
	

		cout << "Change the height: \n";
		cin >> changedHeight;
	 while ( !(  MIN_HEIGHT < changedHeight || changedHeight < MAX_HEIGHT ) )
	{
		cout << "I'm sorry you need to pick a number between 3 and 20 to continue\n";
		cin >> changedHeight;
	}
	return changedHeight;
	
}

//this function changes the width and returns the new width back to main//

int changeWidth(int changedWidth)
{  
		
		cout << "Change the width: \n";
		cin >> changedWidth;
		while ( !( MIN_WIDTH < changedWidth || changedWidth < MAX_WIDTH) )
	{
		cout << "I'm sorry you need to pick a number between 3 and 60 to continue\n";
		cout << "Please try again: \n";
		cin >> changedWidth;
	}
	
	//then changed input goes into main, and then its identifed as a new variable in main, then changed value along with unchanged values go into drawRectangle Method	
	
	return changedWidth;
}

void drawRectangle(int height, int width, char border, char fill)
{
	
	//top border loop//

	for (int top_row = 0; top_row < width; top_row++) 
	{
		cout << border;
		
	}

	cout << "\n";

	//If the x is the generatedCharacterWidth isnt the same as width, then keep adding more characters
	for (int rows = 0; rows < height - 2; rows++)
	{
		cout << border;

		for (int columns = 0; columns < width - 2; columns++) {
			//loop it cout'ing over and over again til it gets width value, stop then continue to next for loop for height then it fills i think
			cout << fill;
		}
		
		cout << border;
		cout << "\n";
	}

	//bottom border loop//

	for (int bottom_row = 0; bottom_row < width; bottom_row++)
	{
		cout << border;
		
	}

}

