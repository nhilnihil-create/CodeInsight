#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, p[5010];
ll A, B, ans = 1e18, f[5010][5010];

int main() {
    scanf("%d %lld %lld", &n, &A, &B);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    memset(f, 0x3f, sizeof(f)), f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (p[i] > j) {
                f[i][j] = min(f[i][j], f[i - 1][j] + A);
                f[i][p[i]] = min(f[i][p[i]], f[i - 1][j]);
            } else {
                f[i][j] = min(f[i][j], f[i - 1][j] + B);
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        ans = min(ans, f[n][i]);
    }
    printf("%lld\n", ans);
    return 0;
}