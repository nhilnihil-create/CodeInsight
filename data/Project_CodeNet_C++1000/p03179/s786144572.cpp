#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define N 3010
ll f[N][N], n, ans = 0;
char str[N];
int main() {
    scanf("%lld%s", &n, str + 1);
    f[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        if (str[i - 1] == '<') {
            f[i][1] = 0;
            for (int j = 2; j <= i; j++)
                f[i][j] = (f[i][j - 1] + f[i - 1][j - 1]) % mod;
        } else {
            f[i][i] = 0;
            for (int j = i - 1; j; j--)
                f[i][j] = (f[i][j + 1] + f[i - 1][j]) % mod;
        }
    }
    for (int i = 1; i <= n; ++i) ans = (ans + f[n][i]) % mod;
    printf("%lld\n", ans);
    return 0;
}