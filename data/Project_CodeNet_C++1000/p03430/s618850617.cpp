#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s; cin >> s;
	int n = s.size();
	int K; cin >> K;
	vector<vector<vector<int> > > dp(n, vector<vector<int> >(n, vector<int>(K+1, 0)));
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < K+1; ++k) dp[i][i][k] = 1;
		if (i < n-1) {
			if (s[i] == s[i+1]) dp[i][i+1][0] = 2;
			else if (K > 0) dp[i][i+1][1] = 2;
		}
	}
	for (int k = 0; k < K+1; ++k) {
		for (int x = 1; x < n; ++x) {
			for (int i = 0; i < n-x; ++i) {
				int j = i+x;
				if (k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]);
				dp[i][j][k] = max(dp[i][j][k], dp[i+1][j][k]);
				dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
				if (s[i] == s[j] && x > 1) dp[i][j][k] = max(dp[i][j][k], dp[i+1][j-1][k] + 2);
				else if (k > 0 && x > 1) dp[i][j][k] = max(dp[i][j][k], dp[i+1][j-1][k-1] + 2);
			}
		}
	}
	cout << dp[0][n-1][K] << endl;
	return 0;
}