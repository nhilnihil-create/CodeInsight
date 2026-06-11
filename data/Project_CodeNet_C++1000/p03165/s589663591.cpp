#include<bits/stdc++.h>
using namespace std;

int dp[3005][3005];

int main() {
	string s, t;
	cin >> s >> t;
	int l1 = s.length(), l2 = t.length();

	for (int i = 0; i <= l1; i++) {
		for (int j = 0; j <= l2; j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else {
				if (s[i - 1] == t[j - 1]) {
					dp[i][j] =  dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
	}
	string ans;
	int i = l1, j = l2;
	//Backtracking
	while (i > 0 && j > 0) {
		if (s[i-1]==t[j-1]) {
			ans.push_back(s[i-1]);
			i--; j--;
		} else if (dp[i][j] == dp[i - 1][j]) {
			i--;
		} else {
			j--;
		}
	}
	//cout << dp[l1][l2] << endl;
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}