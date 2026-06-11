#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define mod 1000000007
#define int long long

void solve() {
	int n;
	cin >> n;
	double p[n];
	int i, j;
	for (i = 0; i < n; i++)cin >> p[i];

	double dp[n + 1][n + 1];
	for (j = 0; j <= n; j++)dp[0][j] = 0;
	for (i = 0; i <= n; i++)dp[i][0] = 1;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			dp[i][j] = (p[i - 1] * dp[i - 1][j - 1]) + ((1 - p[i - 1]) * dp[i - 1][j]);
		}
	}

	cout << setprecision(10) << dp[n][(n / 2) + 1] << endl;
	return;
}

int32_t main() {

	std::ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while (t--)solve();
	return 0;
}