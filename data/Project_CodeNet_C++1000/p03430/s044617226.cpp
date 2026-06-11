#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

string s;
int dp[303][303][303];

int solve(int a, int b, int k) {
	if(dp[a][b][k] < 0) {
		dp[a][b][k] = 0;
		if(a > 0) {
			dp[a][b][k] = max(dp[a][b][k], solve(a - 1, b, k));
		}
		if(b > 0) {
			dp[a][b][k] = max(dp[a][b][k], solve(a, b - 1, k));
		}
		if(a > 0 && b > 0) {
			if(s[a - 1] == s[s.size() - b]) {
				dp[a][b][k] = max(dp[a][b][k], solve(a - 1, b - 1, k) + 1);
			}
			if(k > 0) {
				dp[a][b][k] = max(dp[a][b][k], solve(a - 1, b - 1, k - 1) + 1);
			}
		}
	}
	return dp[a][b][k];
}

signed main() {
	cin >> s;
	int k;
	cin >> k;
	rep(i, s.size() + 2) {
		rep(j, s.size() + 2) {
			rep(k, s.size() + 2) {
				dp[i][j][k] = -1;
			}
		}
	}
	int ans = 1;
	rep(i, s.size()) {
		ans = max(ans, solve(i, s.size() - i, k) * 2);
	}
	rep(i, s.size() - 1) {
		ans = max(ans, solve(i, s.size() - i - 1, k) * 2 + 1);
	}
	cout << ans << endl;
}