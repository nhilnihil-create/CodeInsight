#include <bits/stdc++.h>
using namespace std;
const int N = 3066, MOD = 1e9 + 7;
int n, dp[N][N];
char s[N];
int main()
{
    cin >> n >> (s + 1);
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (s[i - 1] == '<') {
            int c = 0;
            for (int j = 1; j <= i; ++j) {
                dp[i][j] = c;
                c = (c + dp[i - 1][j]) % MOD;
            }
        } else {
            int c = 0;
            for (int j = i; j >= 1; --j) {
                c = (c + dp[i - 1][j]) % MOD;
                dp[i][j] = c;
            }
        }
    }
    cout << accumulate(dp[n] + 1, dp[n] + n + 1, 0ll) % MOD << endl;
}
