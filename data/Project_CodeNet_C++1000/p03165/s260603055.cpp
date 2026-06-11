#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
 
const int MAXN = 3000 + 5;
 
string s, t, ans;
int dp[MAXN][MAXN], from[MAXN][MAXN];
 
void get(int x, int y) {
    if (x == 0 || y == 0) {
        return;
    }
 
    switch (from[x][y])
    {
    case 1:
        ans += s[x - 1];
        get(x - 1, y - 1);
        break;
 
    case 2:
        get(x - 1, y);
        break;
 
    case 3:
        get(x, y - 1);
        break;
    
    default:
        break;
    }
}
 
int main() {
    IOS
 
    cin >> s >> t;
 
    int n = s.length(), m = t.length();
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                from[i][j] = 1;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    from[i][j] = 2;
                } else {
                    dp[i][j] = dp[i][j - 1];
                    from[i][j] = 3;
                }
                //dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
 
    get(n, m);
 
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    cout << '\n';
}