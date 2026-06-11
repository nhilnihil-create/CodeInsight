#include <bits/stdc++.h>
using namespace std;

const int N = 330;

int k, dp[N][N][N];
string s;

void _max(int &a, int b) {
	a = max(a, b);
}

void solve() {
	for (int i = 0; i < s.length(); i++)
		for (int j = 0; j < N; j++)
			dp[i][i + 1][j] = 1;
	
	for (int len = 2; len <= s.length(); len++)
		for (int l = 0; l + len <= s.length(); l++) {
			int r = l + len;
			for (int cnt = 0; cnt <= k; cnt++) {
				dp[l][r][cnt] = max(dp[l + 1][r][cnt], dp[l][r - 1][cnt]);
				if (s[l] == s[r - 1])
					_max(dp[l][r][cnt], 2 + dp[l + 1][r - 1][cnt]);
				else if (cnt)
					_max(dp[l][r][cnt], 2 + dp[l + 1][r - 1][cnt - 1]);
			}
		}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> s >> k;
	solve();
	cout << dp[0][s.length()][k];
}