
// author: arshit_babariya

#include <bits/stdc++.h>

using namespace std;
#define fast			ios::sync_with_stdio(0);cin.tie(0);
#define ll 				long long int
#define INF 			1e18L
#define precision(x)	fixed << setprecision(x)
const ll mod = 1e9 + 7;

ll gcd(ll a, ll b) {
	if (b == 0)  return a;
	return gcd(b , a % b);
}


ll powm(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1)
			res = (res * 1LL * a) % mod;
		b >>= 1LL;
		a = (a * 1LL * a) % mod;
	}
	return res;
}

//--------------------------------------------------------------------------------------------------------------------------//



int main() {
	fast
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	double a[n + 1], dp[n + 1][n + 1];
	for (int i = 0; i < n; i++) cin >> a[i + 1];
	a[0] = 0;
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] * (1 - a[i]);
				continue;
			}
			dp[i][j] = a[i] * dp[i - 1][j - 1] + (1.0 - a[i]) * dp[i - 1][j];

		}
	}
	double ans = 0;
	for (int i = n; i >= (n + 1) / 2; i--) {
		ans += dp[n][i];
	}
	cout << precision(10) << ans << endl;
	return 0;
}


