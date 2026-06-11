#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define int long long
#define fi first
#define se second
#define pll pair<LL, LL>
#define pii pair<LL, LL>

const LL MAXN = 3e3+5;
int N;
string s;
int mod = 1e9+7;
int dp[MAXN][MAXN];
int sum[MAXN][MAXN];

signed main() {
    cin >> N;
    cin >> s;
    dp[1][1] = 1;
    sum[1][1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (s[i-2] == '<') {
                // 1 ~ j-1
                dp[i][j] = (dp[i][j] + sum[i-1][j-1]) % mod;
            } else {
                // j ~ i-1
                if (i-1 >= j)
                    dp[i][j] = (dp[i][j] + (sum[i-1][i-1] - sum[i-1][j-1] + mod) % mod) % mod;
            }
            //cout << dp[i][j] << endl;
            sum[i][j] = (sum[i][j-1] + dp[i][j]) % mod;
        } 
    }
    cout << sum[N][N] << endl;
    return 0;
}