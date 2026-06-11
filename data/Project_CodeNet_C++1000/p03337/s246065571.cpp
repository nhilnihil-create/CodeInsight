#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int X,Y,Z,A,B;

	cin >> A >> B;

	X = A + B;
	Y = A - B;
	Z = A * B;

	if(X >= Y && X >= Z){

		cout << X << "\n";

	} else if(Y >= X && Y >= Z){

		cout << Y << "\n";

	} else if(Z >= X && Z >= Y){

			cout << Z << "\n";
		}

	return 0;

}
