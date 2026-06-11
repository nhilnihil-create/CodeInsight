#include "bits/stdc++.h"
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int n = 64;
	vector<vector<string>> data0(n / 2, vector<string>(n, "."));
	vector<vector<string>> data1(n / 2, vector<string>(n, "#"));
	for (int i = 0; i < B - 1; ++i) {
		data0[2 * (i / (n / 2))][2 * (i % (n / 2))] = "#";
	}
	for (int i = 0; i < A - 1; ++i) {
		data1[1 + 2 * (i / (n / 2))][2 * (i % (n / 2))] = ".";
	}
	cout << n << " " << n << endl;
	for (int i = 0; i < (n / 2); ++i) {
		for (int j = 0; j < n; ++j) {
			cout << data0[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < (n / 2); ++i) {
		for (int j = 0; j < n; ++j) {
			cout << data1[i][j];
		}
		cout << endl;
	}
}
