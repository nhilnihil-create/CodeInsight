/**
 * There is a start and there is no end in the space. ---Infinity.
 * It ruins and goes though there is also a start in stars. ---Finite.
 * Only the man who has wisdom can read the most foolish one from the history.
 * Fishes living in the sea doesn't know the life in the land.
 * It also ruins and goes if they have wisdom.
 * It funnier that man exceeds the speed of light than fish start living in the land.
 * It can be said that this is an final ultimatum from the god to the people who can fight.
 *
 * Steins;Gate
 */

#include <bits/stdc++.h>

typedef long long LL;
const int N = 5010;

LL f[N][N];
int a[N], p[N];

int main() {

    int n;
    LL A, B;
    scanf("%d%lld%lld", &n, &A, &B);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        p[a[i]] = i;
    }
    memset(f, 0x3f, sizeof(f));
    /// DP
    f[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            /// f[i][j]
            /*for(int k = 0; k < i; k++) {
                /// f[i][j] <- f[i - 1][k]
                if(p[i] < p[k]) {
                    f[i][j] = std::min(f[i][j], f[i - 1][k] + A);
                }
                else {
                    f[i][j] = std::min(f[i][j], f[i - 1][k] + B);
                }
            }*/
            if(p[i] < p[j]) {
                f[i][j] = f[i - 1][j] + A;
            }
            else {
                f[i][j] = f[i - 1][j] + B;
                f[i][i] = std::min(f[i][i], f[i - 1][j]);
            }
        }
        /*for(int j = 0; j <= i; j++) {
            printf("%3lld ", f[i][j]);
        }
        puts("");*/
    }


    LL ans = 4e18;
    for(int i = 0; i <= n; i++) {
        ans = std::min(ans, f[n][i]);
    }
    printf("%lld\n", ans);
    return 0;
}
