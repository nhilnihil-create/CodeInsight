#include "bits/stdc++.h"
using namespace std;

int main() {
	int A ,B;
	cin >> A >> B;
	vector<vector<string>> data0(50, vector<string>(100, "."));
	vector<vector<string>> data1(50, vector<string>(100, "#"));	
	for (int i = 0; i < B-1; ++i) {
		data0[2 * (i / 50)][2 * (i % 50)] = "#";
	}	
	for (int i = 0; i < A-1; ++i) {
		data1[1 + 2 * (i / 50)][2 * (i % 50)] = ".";
	}
	cout << 100 << " "<<100 << endl;
	for (int i = 0;i<50;++i) {
		for (int j = 0;j<100;++j) {
			cout << data0[i][j];
		}
		cout << endl;
	}	
	for (int i = 0; i < 50; ++i) {
		for (int j = 0; j < 100; ++j) {
			cout << data1[i][j];
		}
		cout << endl;
	}
}
