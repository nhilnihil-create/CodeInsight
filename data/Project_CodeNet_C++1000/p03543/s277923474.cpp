#include <bits/stdc++.h>

using namespace std;

int main()
{
	string N;
	char checkValue;
	getline(cin, N);
	checkValue = N[1];
	if((N[0] == checkValue && N[2] == checkValue) || (N[2] == checkValue && N[3] == checkValue))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}