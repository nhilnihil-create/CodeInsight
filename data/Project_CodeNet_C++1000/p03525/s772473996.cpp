#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n;
	cin >> n;
	vector<ll> d(n + 1, 0);
	for (ll i = 1; i <= n; ++i)cin >> d[i];
	sort(d.begin(), d.end());
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
	dp[0][0] = 100;
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j <= i; ++j) {
			dp[i + 1][i] = max(dp[i + 1][i], min(dp[i][j], d[i + 1] - d[j]));
			dp[i + 1][j] = max(dp[i + 1][j], min(dp[i][j], d[i + 1] - d[i]));
		}
	}
	ll ans = 0;
	for (ll i = 0; i < n; ++i) {
		ans = max(ans, min(dp[n][i], 24 - d[i] - d[n]));
	}
	cout << ans << endl;
}
