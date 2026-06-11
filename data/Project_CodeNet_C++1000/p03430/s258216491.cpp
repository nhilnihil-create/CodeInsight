#include <bits/stdc++.h>
using namespace std;

const int N = 305;
const int INF = 1e9;

string s;
int n, k;
int dp[N][N][N];
int res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s >> k;
	n = s.size();
	s = ' ' + s;
	s = s + '&';

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int c = 0; c <= k; ++c) dp[i][j][c] = -INF;
		}
	}
	for (int i = 0; i <= n + 1; ++i) dp[0][i][0] = 0;
	for (int i = 0; i <= n + 1; ++i) dp[i][n + 1][0] = 0;
	for (int gap = n; gap >= 1; --gap) {
		for (int i = 1; i <= n - gap + 1; ++i) {
			int j = i + gap - 1;
			for (int c = 0; c <= k; ++c) {
				dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j][c]);
				dp[i][j][c] = max(dp[i][j][c], dp[i][j + 1][c]);
				
				bool more = (s[i] == s[j] ? 0 : 1);
				if (c >= more) {
					dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j + 1][c - more] + (i == j ? 1 : 2));
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int c = 0; c <= k; ++c) {
				res = max(res, dp[i][j][c]);
			}
		}
	}

	cout << res << endl;
}