#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 300;

char str[MAXN + 1];

int dp[MAXN + 1][MAXN + 1][MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, k;
    ios::sync_with_stdio(false);
    cin >> str + 1;
    int n = strlen(str + 1);
    cin >> k;
    for(i = 1; i <= n; i++) {
        for(j = 0; j <= k; j++) {
            dp[i][i][j] = 1;
        }
    }
    for(int len = 1; len <= n; len++) {
        for(i = 1; i + len <= n; i++) {
            int l = i, r = i + len;
            for(j = 0; j <= k; j++) {
                dp[l][r][j] = max(dp[l + 1][r][j], dp[l][r - 1][j]);
                if(j >= (str[l] != str[r])) {
                    dp[l][r][j] = max(dp[l][r][j], dp[l + 1][r - 1][j - (str[l] != str[r])] + 2);
                }
            }
            for(j = 1; j <= k; j++) {
                dp[l][r][j] = max(dp[l][r][j], dp[l][r][j - 1]);
            }
        }
    }
    cout << dp[1][n][k];
    //cin.close();
    //cout.close();
    return 0;
}
