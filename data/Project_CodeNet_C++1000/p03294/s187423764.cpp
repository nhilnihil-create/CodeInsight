// atc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include    <algorithm>
using namespace std;

int main()
{
	int x;
	cin >> x;
	vector<int> A(x,0);

	for (int i = 0; i < x; i++) {
		cin >> A[i];
	}

	int sum = 0;

	for (int i = 0; i < x; i++) {
			sum +=  A[i];
	}
	sum -= x;

	cout << sum << endl;


	system("pause");

	return 0;

}
