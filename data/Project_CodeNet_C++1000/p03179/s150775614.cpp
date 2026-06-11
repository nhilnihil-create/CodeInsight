#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define N 3002
int f[N][N], n, ans;
char c[N];
int main() {
    scanf("%d%s", &n, c + 1);
    f[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        if (c[i - 1] == '<')
            for (int j = 2; j <= i; j++)
                f[i][j] = (f[i][j - 1] + f[i - 1][j - 1]) % mod;
        else
            for (int j = i - 1; j; j--)
                f[i][j] = (f[i][j + 1] + f[i - 1][j]) % mod;
    }
    for (int i = 1; i <= n; ++i) ans = (ans + f[n][i]) % mod;
    printf("%d\n", ans);
    return 0;
}