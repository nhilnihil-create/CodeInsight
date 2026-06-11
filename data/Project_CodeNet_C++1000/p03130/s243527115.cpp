#include "bits/stdc++.h"
using namespace std;


int main() {

	vector<int> vways;
	int number;
	int flag = 0;

	for (int i = 0; i < 4; i++) {
		number = 0;
		vways.push_back(number);
	}

	for (int i = 0; i < 6; i++) {
		cin >> number;
		vways.at(number-1)++;
	}

	for (int i = 0; i < 4; i++) {
		if (vways.at(i) >= 3) {
			flag = 1;
		}
	}


	if (flag == 1) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}


	return 0;

}
