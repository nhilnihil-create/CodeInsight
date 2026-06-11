#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const LL MOD = 1000000007LL;
int dp[300][301][301];
int main() {
	string S;
	cin >> S;
	int K;
	cin >> K;
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j <= K; j++) dp[i][i + 1][j] = 1;
	}
	for (int len = 2; len <= S.size(); len++) {
		for (int i = 0; i + len <= S.size(); i++) {
			for (int j = 0; j <= K; j++) {
				if (S[i] == S[i + len - 1]) {
					dp[i][i + len][j] = max(dp[i][i + len][j], dp[i + 1][i + len - 1][j] + 2);
				}
				dp[i][i + len][j] = max(dp[i][i + len][j], dp[i + 1][i + len][j]);
				dp[i][i + len][j] = max(dp[i][i + len][j], dp[i][i + len - 1][j]);
				if (j > 0) {
					dp[i][i + len][j] = max(dp[i][i + len][j], dp[i + 1][i + len - 1][j - 1] + 2);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= K; i++) ans = max(ans, dp[0][S.size()][i]);
	cout << ans << endl;
}