#include <bits/stdc++.h>
using namespace std;

int n, m, d[30][30], c[500][500], ans = 2e9, w[30][3];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			cin >> d[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
			c[i][j]--;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				w[k][(i + j) % 3] += d[c[i][j]][k];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < m; k++) {
				if (i == j || j == k || k == i)
					continue;
				ans = min(ans, w[i][0] + w[j][1] + w[k][2]);
			}
	cout << ans << endl;
}
