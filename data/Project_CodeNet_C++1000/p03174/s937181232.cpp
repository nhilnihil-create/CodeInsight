#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;

int main() {
	FASTIO
	int n;
	cin >> n;
	vector<vector<int>> g(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> g[i][j];
		}
	}
	int woman = (1 << n);
	vector<vector<int>> dp(n + 1, vector<int>(woman));
	dp[0][0] = 1;
	constexpr ll MOD = 1e9 + 7;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < woman; j++) {
			if (i == __builtin_popcount(j)) {
				for (int k = 0; k < n; k++) {
					if (g[i][k + 1] && (j & (1 << k)))
						dp[i][j] = (dp[i][j] + dp[i - 1][j ^ (1 << k)]) % MOD;
				}
			}
		}
	}
	cout << dp[n][woman - 1] << endl;
}
