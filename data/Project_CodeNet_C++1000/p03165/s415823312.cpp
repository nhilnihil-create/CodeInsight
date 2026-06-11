#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define mod 1000000007
#define int long long

void solve() {
	string s1, s2;
	cin >> s1 >> s2;
	int m = s1.size();
	int n = s2.size();
	int dp[m + 1][n + 1];
	int i, j;
	for (i = 0; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			if (i == 0 || j == 0)dp[i][j] = 0;
			else if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	// cout << dp[m][n] << endl;

	string str = "";
	i = m;
	j = n;

	while (i > 0 && j > 0) {
		if (s1[i - 1] == s2[j - 1]) {
			str += s1[i - 1];
			i--;
			j--;
		}
		else {
			if (dp[i - 1][j] > dp[i][j - 1])i--;
			else j--;
		}
	}

	reverse(str.begin(), str.end());
	cout << str << endl;
	return;
}

int32_t main() {

	std::ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while (t--)solve();
	return 0;
}