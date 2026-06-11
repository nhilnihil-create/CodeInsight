#include <bits/stdc++.h>
using namespace std;
const int N = 16;
const int N2 = (1 << N);
int n, a[N][N];
long long cost[N2], dp[N2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int p2n = (1 << n);

	for (int bm = 0; bm < p2n; bm++) {
		for (int i = 1; i < n; i++) {
			if ((bm & (1 << i)) == 0) continue;
			for (int j = 0; j < i; j++) {
				if ((bm & (1 << j)) == 0) continue;
				cost[bm] += (long long) a[i][j];
			}
		}
	}

	for (int bm = 1; bm < p2n; bm++) {
		long long ans = 0;
		for (int sbm = bm; sbm > 0; sbm = (sbm - 1) & bm) {
			if ((sbm & bm) != sbm) continue;
			int cbm = bm ^ sbm;
			ans = max(ans, cost[sbm] + dp[cbm]);
		}
		dp[bm] = ans;
	}

	cout << dp[p2n - 1] << '\n';

	return 0;
}
