#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	string s;
	int K;
	cin >> s >> K;
	vector<vector<vector<int> > > dp(s.length(), vector<vector<int> >(s.length(), vector<int>(K + 1, 0)));
	for (int i = s.length() - 1; i >= 0; i--) {
		for (int k = 0; k <= K; k++) {
			dp[i][i][k] = 1;
		}
		for (int j = i + 1; j < s.length(); j++) {
			dp[i][j][0] = max(dp[i + 1][j][0], dp[i][j - 1][0]);
			dp[i][j][0] = max(dp[i][j][0], dp[i + 1][j - 1][0] + (s[i] == s[j]) * 2);
			for (int k = 1; k <= K; k++) {
				dp[i][j][k] = max(dp[i + 1][j][k], dp[i][j - 1][k]);
				dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j - 1][k - 1] + 2);
				dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j - 1][k] + (s[i] == s[j]) * 2);
			}
		}
	}
	cout << dp[0][s.length() - 1][K] << endl;
    return 0;
}