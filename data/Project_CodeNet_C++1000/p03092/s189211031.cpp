#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int n, a, b;
int f[5001];
long long dp[5001][5001];

long long solve(int i, int prv) {
	if (i == n) return 0;
	if (dp[i][prv] != -1) return dp[i][prv];

	long long ans = INF;
	if (f[i] < prv) {
		ans = min(ans, solve(i+1, prv) + b);
	} else {
		ans = min(ans, solve(i+1, f[i]));
		ans = min(ans, solve(i+1, prv) + a);
	}
	return dp[i][prv] = ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		cin >> f[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';
 
	return 0;
}