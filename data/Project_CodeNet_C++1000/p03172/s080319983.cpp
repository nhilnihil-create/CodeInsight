#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define mod 1000000007
#define int long long

void solve() {
	int n, k;
	cin >> n >> k;
	int a[n];
	int i, j;
	for (i = 0; i < n; i++)cin >> a[i];
	int dp[n + 1][k + 1];

	// for (i = 0; i < n; i++)cout << a[i] << " ";
	// cout << endl;

	for (j = 0; j <= k; j++)dp[0][j] = 0;
	for (i = 0; i <= n; i++)dp[i][0] = 1;


	for (j = 0; j <= k; j++) {
		if (a[0] >= j)dp[1][j] = 1;
		else dp[1][j] = 0;
	}


	for (i = 2; i <= n; i++) {
		for (j = 1; j <= k; j++) {
			int x = dp[i][j - 1];
			int y = dp[i - 1][j];
			int z = 0;
			if (j - a[i - 1] - 1 >= 0)z = dp[i - 1][j - a[i - 1] - 1];
			// cout << i << "," << j << " -> " << endl;
			// cout << j - a[i - 1] - 1 << endl;
			// cout << x << ", " << y << ", " << z << endl;
			dp[i][j] = (mod + ((x % mod) + (y % mod) - (z % mod)) % mod) % mod;
		}
	}

	// for (i = 0; i <= n; i++) {
	// 	for (j = 0; j <= k; j++)cout << dp[i][j] << " ";
	// 	cout << endl;
	// }

	cout << dp[n][k] << endl;
	return;
}

int32_t main() {

	std::ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	solve();
	return 0;
}