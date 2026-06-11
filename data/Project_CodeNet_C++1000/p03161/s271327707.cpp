#include<bits/stdc++.h>
using namespace std;
#define fastio std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define F first
#define S second
#define pb push_back
#define M 1000000007
#define inf 1e18
#define jam(x) cout<<"Case #"<<x<<": "

int32_t main() {
	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n, k;
	cin >> n >> k;
	std::vector<int> h(n);
	std::vector<int> dp(n, INT_MAX);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	for (int i = 0; i <= k; ++i) {
		dp[i] = abs(h[0] - h[i]);
	}

	for (int i = k + 1; i < n; i++) {
		for (int j = 1; j <= k; j++) {

			dp[i] = min( dp[i] , dp[i - j] + abs( h[i] - h[i - j] ) );
		}
	}
	cout << dp[n - 1];

	return 0;
}