#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define mod 1000000007
#define int long long

void solve() {
	int n, k;
	cin >> n >> k;
	int i, j;
	int a[n];
	for (i = 0; i < n; i++)cin >> a[i];
	int dp[k + 1] = {0};
	dp[0] = 0;
	for (i = 1; i <= k; i++) {
		for (j = 0; j < n; j++) {
			if (i - a[j] >= 0) {
				if (dp[i - a[j]] == 0) {
					dp[i] = 1;
					break;
				}
			}
		}
	}

	// for (i = 0; i <= k; i++)cout << dp[i] << " ";
	// cout << endl;

	if (dp[k] == 1)cout << "First" << endl;
	else cout << "Second" << endl;

	return;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while (t--)solve();
	return 0;
}