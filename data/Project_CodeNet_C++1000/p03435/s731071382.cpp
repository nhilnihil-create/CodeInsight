#include "bits/stdc++.h"
using namespace std;

int main() {
	vector<vector<int>> data(3, vector<int>(3));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> data[i][j];
		}
	}
	
	for (int i = 1; i < 3; ++i) {
		int num = data[i][0] - data[i-1][0];
		for (int j = 0; j < 3; ++j) {
			if (num != data[i][j] - data[i - 1][j]) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}