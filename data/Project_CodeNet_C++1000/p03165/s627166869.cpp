#include <bits/stdc++.h>
 
using namespace std;

const int N = 3005;

int dp[N][N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s, t;
    cin >> s >> t;
    int n = (int) s.size(), m = (int) t.size();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) continue;
            if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
        }
    }
    int x = n, y = m;
    string ans = "";
    while (x > 0 && y > 0) {
        if (s[x - 1] == t[y - 1]) {
            ans += s[x - 1];
            x--, y--;
        }
        else if (dp[x - 1][y] > dp[x][y - 1]) x--;
        else y--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}