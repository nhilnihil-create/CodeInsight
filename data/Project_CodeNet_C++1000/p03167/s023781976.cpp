#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
const int MAXN = 1e3 + 1;
const int MOD = 1e9 + 7;
int H, W;
string m[MAXN];
vector<vector<int> > dp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> H >> W;
	for (int i = 0; i < H; ++i) {
		cin >> m[i];
	}
	dp.resize(H, vector<int>(W, 0));
	dp[0][0] = (int)(m[0][0] == '.');
	for (int i = 1; i < H; ++i) dp[i][0] = (int)(dp[i - 1][0] && m[i][0] == '.');
	for (int i = 1; i < W; ++i) dp[0][i] = (int)(dp[0][i-1] && m[0][i] == '.');
	for (int i = 1; i < H; ++i) {
		for (int j = 1; j < W; ++j) {
			if (m[i][j] == '#') continue;
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}
	cout << dp[H - 1][W - 1] << '\n';
	return 0;
}