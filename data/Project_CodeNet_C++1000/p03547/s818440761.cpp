#include<iostream>
using namespace std;
int main() {
	char x, y;
	int dx, dy;
	cin >> x;
	switch (x)
	{
	case 'A':dx = 10; break;
	case 'B':dx = 11; break;
	case 'C':dx = 12; break;
	case 'D':dx = 13; break;
	case 'E':dx = 14; break;
	case 'F':dx = 15; break;
	}
	cin >> y;
		switch (y)
		{
		case 'A':dy= 10; break;
		case 'B':dy= 11; break;
		case 'C':dy= 12; break;
		case 'D':dy= 13; break;
		case 'E':dy= 14; break;
		case 'F':dy= 15; break;
	}
		if (dx < dy) cout << "<";
		else if (dx > dy) cout << ">";
		else if (dx == dy)cout << "=";

		return(0);


}