#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int h, w;
    cin >> h >> w;
    vector<vector<int>> dp(h, vector<int>(w, 0));
    vector<vector<char>> grid(h, vector<char>(w));
    dp[0][0] = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == '.') {
                if (i - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }
    cout << dp[h - 1][w - 1] << endl;
	return 0;
}