#include <bits/stdc++.h>
using namespace std;

const int nm = 501;
int n, m, q;

int a[nm][nm], b[nm + 1][nm + 1];

int main() {
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		a[l][r]++;
	}
	for (int i = 0; i < nm; i++)
		for (int j = 0; j < nm; j++)
			b[i + 1][j + 1] = a[i][j] + b[i + 1][j] + b[i][j + 1] - b[i][j];
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << b[r + 1][r + 1] - b[r + 1][l] - b[l][r + 1] + b[l][l] << endl;
	}

}
