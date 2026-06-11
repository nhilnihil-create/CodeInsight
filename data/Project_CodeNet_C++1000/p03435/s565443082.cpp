#include <bits/stdc++.h>
using namespace std;

#define MAX 3

int main() {
	int c[MAX][MAX], a[MAX], b[MAX];
	a[0] = 0;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cin >> c[i][j];
	for (int i = 0; i < MAX; i++)
		b[i] = c[0][i] - a[0];
	for (int i = 1; i < MAX; i++)
		a[i] = c[i][0] - b[0];
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			if (a[i] + b[j] != c[i][j]) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}
