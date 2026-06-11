#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n, m, q;
	cin >> n >> m >> q;
	long long d[n][n];
	long long sum[n][n];
	fill(d[0], d[0]+n*n, 0);
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		d[l-1][r-1]++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0) {
				if (j == 0)
					sum[0][0] = d[0][0];
				else
					sum[i][j] = sum[i][j-1] + d[i][j];
			} else if (j == 0) {
				if (i == 0)
					sum[0][0] = d[0][0];
				else
					sum[i][j] = sum[i-1][j] + d[i][j];
			} else {
				sum[i][j] = sum[i-1][j] + sum[i][j-1] + d[i][j] - (sum[i-1][j-1]);
			}
		}
	}
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		long long ans;
		if (a-2 < 0)
			ans = sum[b-1][b-1];
		else
			ans = sum[b-1][b-1] - (sum[a-2][b-1] + sum[b-1][a-2] - sum[a-2][a-2]);
		cout << ans << endl;
	}
	return 0;
}