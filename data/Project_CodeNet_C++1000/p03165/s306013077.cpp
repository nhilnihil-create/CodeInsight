#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long int ll;

// int dp[3000][3000];
int n, m;
// int find(string s, string t, int i, int j) {
// 	if (i >= n || j >= m)
// 		return 0;

// 	if (dp[i][j] != -1)
// 		return dp[i][j];

// 	if (s[i] == t[j])
// 		return dp[i][j] = find(s, t, i + 1, j + 1) + 1;

// 	return dp[i][j] = max(find(s, t, i + 1, j), find(s, t, i, j + 1));
// }


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string s, t;
	cin >> s >> t;
	n = s.length(), m = t.length();
	// dp.resize(n + 1, vector<int>(m + 1, -1));
	// memset(dp, -1, sizeof(dp));
	// find(s, t, 0, 0);
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int i = n, j = m;
	string res;
	while (i > 0 && j > 0) {
		if (s[i - 1] == t[j - 1]) {
			res += s[i - 1];
			i--;
			j--;
		} else {
			if (dp[i][j - 1] > dp[i - 1][j])
				j--;
			else
				i--;
		}
	}
	reverse(res.begin(), res.end());
	cout << res;
	return 0;
}
