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
    int i, j, n, k;
    ios::sync_with_stdio(false);
    cin >> str + 1;
    cin >> k;
    n = strlen(str + 1);
    for(i = 1; i <= n; i++) {
        for(j = 0; j <= k; j++) {
            dp[i][i][j] = 1;
        }
    }
    for(i = 1; i < n; i++) {
        if(str[i] == str[i + 1]) {
            dp[i][i + 1][0] = 1;
        }
        else {
            dp[i][i + 1][1] = 1;
        }
        for(j = 1; j <= k; j++) {
            dp[i][i + 1][j] = max(dp[i][i + 1][j], dp[i][i + 1][j - 1]);
        }
    }
    for(int len = 1; len < n; len++) {
        for(int l = 1; l + len <= n; l++) {
            int r = l + len;
            for(i = 0; i <= k; i++) {
                dp[l][r][i] = max(dp[l][r - 1][i], dp[l + 1][r][i]);
                if(i >= (str[l] != str[r])) {
                    dp[l][r][i] = max(dp[l][r][i], dp[l + 1][r - 1][i - (str[l] != str[r])] + 2);
                }
            }
            for(i = 1; i <= k; i++) {
                dp[l][r][i] = max(dp[l][r][i], dp[l][r][i - 1]);
            }
        }
    }
    cout << dp[1][n][k];
    //cin.close();
    //cout.close();
    return 0;
}
