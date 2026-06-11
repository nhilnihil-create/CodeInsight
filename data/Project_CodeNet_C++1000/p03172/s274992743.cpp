#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	constexpr ll MOD = 1e9 + 7;
	vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i - 1][j] += dp[i - 1][j - 1] ;
			dp[i - 1][j] %= MOD;
		}
		for (int j = 0; j <= k; j++) {
			ll u = (j > a[i - 1])?dp[i - 1][j - a[i - 1] - 1]:0;
			dp[i][j] += dp[i - 1][j] - u + MOD;
			dp[i][j] %= MOD;
		}
	}
	cout << dp[n][k] << endl;
}
