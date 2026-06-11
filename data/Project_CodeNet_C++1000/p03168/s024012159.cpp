#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define MOD 1000000007
#define ar array
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int32_t main() {
	fast_io;

	// int t; cin >> t;
	// while (t--) {
		
	// }
	int n;
	cin >> n;
	vector<double> p_head(n);
	vector<double> p_tail(n);
	for (int i = 0; i < n; i++) {
		cin >> p_head[i];
		p_tail[i] = 1 - p_head[i];
	}
	vector<vector<double>> dp(n + 1, vector<double> (n + 1, 0));
	dp[0][0] = 1;
	double tail_prob = 1;
	for (int i = 1; i <= n; i++) {
		tail_prob *= p_tail[i - 1];
		dp[i][0] = tail_prob;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i - 1][j]*(1 - p_head[i - 1]) + dp[i - 1][j - 1]*p_head[i - 1];
		}
	}
	double res = 0;
	for (int head = (n + 1)/2; head <= n; head++) {
		res += dp[n][head];
	}
	cout << fixed;
	cout << setprecision(10) << res << endl;

	return 0;
}