#include <bits/stdc++.h>
using namespace std;

const int nm = 100;
int n, f[nm], p[nm][11];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0, b; j < 10; j++) {
			cin >> b;
			f[i] <<= 1;
			f[i] |= b;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 11; j++)
			cin >> p[i][j];

	int m = -1e9;
	for (int i = 1, prf; i < 1 << 10; i++) {
		prf = 0;
		for (int j = 0; j < n; j++) {
			prf += p[j][__builtin_popcount(i & f[j])];
		}
		m = max(m, prf);
	}
	cout << m << endl;
}
