#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include<string>
using namespace std;
#define ll long long int
#define maxn 100005

void _init() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}



int main() {
	_init();

	string s, t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	int dp[n + 1][m + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	//cout << "maxLength" << dp[n][m] << endl;
	string res = "";
	while (n > 0 && m > 0) {
		if (s[n - 1] == t[m - 1]) {
			res += s[n - 1];
			n--, m--;
		}
		else {
			if (dp[n][m] == dp[n - 1][m])n--;
			else m--;
		}
	}

	reverse(res.begin(), res.end());

	cout << res << endl;

	return 0;
}







