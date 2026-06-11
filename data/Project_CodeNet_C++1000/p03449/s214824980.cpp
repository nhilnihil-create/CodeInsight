// atc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include    <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> A(n);
	vector<int> B(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	int max = 0, tmp = 0;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < i+1; j++) {
			tmp += A[j];
		}
		for (int k = i; k < n; k++) {
			tmp += B[k];
		}

		if (tmp > max) max = tmp;
		
		tmp = 0;

	}

	cout << max;


	system("pause");

	return 0;

}
