#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
const int MAXN = 3001;
const int INF = 1e9 + 7;
string s,t,ans;
vector<vector<int> > dp;
void solve(int l, int r) {
	if (l == 0 || r == 0) {
		if (dp[l][r]) {
			if (l == 0) ans = s[0] + ans;
			else ans = t[0] + ans;
		}
		return;
	}
	if (s[l]==t[r] && dp[l][r] == dp[l - 1][r - 1] + 1) {
		solve(l - 1, r - 1);
		ans = ans + s[l];
	}
	else if (dp[l][r] == dp[l][r - 1]) {
		solve(l, r - 1);
	}
	else solve(l - 1, r);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> t;
	dp.resize(s.length() + 1, vector<int>(t.length() + 1,0));
	dp[0][0] = (int)(s[0] == t[0]);
	for (int i = 1; i < s.length(); ++i) {
		dp[i][0] = max(dp[i-1][0],(int)(s[i] == t[0]));
	}
	for (int i = 1; i < t.length(); ++i) {
		dp[0][i] = max(dp[0][i - 1], (int)(s[0] == t[i]));
	}
	for (int i = 1; i < s.length(); ++i) {
		for (int j = 1; j < t.length(); ++j) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (s[i] == t[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
		}
	}
	ans = "";
	solve(s.length() - 1, t.length() - 1);
	cout << ans << '\n';
	return 0;
}