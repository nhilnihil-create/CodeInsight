#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;

int main() {
	FASTIO
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 1e15));
	for (int i = 0; i < n; i++) {
		dp[i][i] = 0;
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i + len - 1 < n; i++) {
			int j = len + i - 1;
			ll u = 0;
			for(int r = i ; r <= j ; r++){
				u += a[r];
			}
			for (int k = i; k < len + i - 1; k++) {

				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + u );
//				clog << i << ' ' << j << ' ' << k << ' ' << dp[i][j] << ' ' << dp[i][k] << ' ' << dp[k + 1][j] << endl;

			}
		}
	}
	cout << dp[0][n - 1] << endl;

}
//
//
//2 3 4
//2 3 4
//5 7
//11 or 9
//dp[i][j] = dp[i][k] + dp[k + 1][j] k = i...j
//j = i + len