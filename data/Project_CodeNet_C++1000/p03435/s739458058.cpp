#include<bits/stdc++.h>
using namespace std;
int main () {
	long long  c[4][4];
	long long  a[4];
	long long b[4];
	for (int i=1; i<=3; i++) {
		for (int j=1; j<=3; j++) {
			cin >> c[i][j];
		}
	}
	b[1] = c[1][1];
	b[2] = c[1][2];
	b[3] = c[1][3];
	a[1] = 0;
	a[2] = c[2][2] - b[2];
	a[3] = c[3][3] - b[3];
	for (int i=1; i<=3; i++) {
		for (int j=1; j<=3; j++) {
			if (c[i][j]!=a[i]+b[j]) {
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
	return 0;
}