#include <iostream>

using namespace std;

int main()
{
	string S;
	cin >> S;
	string fes = "FESTIVAL";

	for (int i = 0; i < S.length()-fes.length(); i++) {
		cout << S[i];
	}

	cout << endl;
}