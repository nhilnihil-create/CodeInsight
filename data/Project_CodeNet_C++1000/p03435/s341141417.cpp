#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<vector<int>>c(3, vector<int>(3, 0));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> c[i][j];
		}
	}

	int a[3], b[3];
	a[0] = 0;
	for (int i = 0; i < 3; i++) {
		if (i)a[i] = c[i][0] - b[0];
		b[i] = c[i][i] - a[i];
	}

	bool match = true;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (c[i][j] != a[i] + b[j])match = false;
		}
	}
	cout << (match ? "Yes" : "No") << endl;

	return 0;
}