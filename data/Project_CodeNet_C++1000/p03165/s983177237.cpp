#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -INF));
    vector<vector<int>> rev(n + 1, vector<int>(m + 1));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i + 1 <= n) {
                if (dp[i + 1][j] < dp[i][j]) {
                    dp[i + 1][j] = dp[i][j];
                    rev[i + 1][j] = 0;
                }
            }
            if (j + 1 <= m) {
                if (dp[i][j + 1] < dp[i][j]) {
                    dp[i][j + 1] = dp[i][j];
                    rev[i][j + 1] = 1;
                }
            }
            if (i + 1 <= n && j + 1 <= m && s[i] == t[j]) {
                if (dp[i + 1][j + 1] < dp[i][j] + 1) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    rev[i + 1][j + 1] = 2;
                }
            }
        }
    }
    vector<char> ans(3001);
    int ns = n;
    int nt = m;
    int at = dp[n][m] - 1;
    while (ns || nt) {
        if (rev[ns][nt] == 0)
            ns--;
        else if (rev[ns][nt] == 1)
            nt--;
        else {
            ns--;
            nt--;
            ans[at] = s[ns];
            at--;
        }
    }
    for (int i = 0; i < dp[n][m]; i++)
        cout << ans[i];
    cout << endl;

	return 0;
}