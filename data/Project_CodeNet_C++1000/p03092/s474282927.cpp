#include <bits/stdc++.h>
#define rep(i, n) for (rint i = 1; i <= (n); i ++)
#define re0(i, n) for (rint i = 0; i < (int) n; i ++)
#define travel(i, u) for (rint i = head[u]; i; i = e[i].nxt)
#define rint register int
using namespace std;

typedef long long lo;

template<typename tp> inline void read(tp &x) {
    x = 0; char c = getchar(); int f = 0;
    for (; c < '0' || c > '9'; f |= c == '-', c = getchar());
    for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
    if (f) x = -x;
}
#define int long long
const int N = 5555;
int n, A, B, a[N], id[N], dp[N][N];

inline void U(int &x, int y) {
    x = min(x, y);
}

signed main(void) {
    read(n); read(A); read(B);
    swap(A, B);
    rep (i, n) read(a[i]), id[a[i]] = i;
    memset(dp, 38, sizeof dp);
    int tmp = dp[0][0];
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int pre = 0; pre <= n; pre++)
            if (dp[i - 1][pre] != tmp) {
                int np = id[i];
                if (np > pre) {
                    U(dp[i][np], dp[i - 1][pre]);
                    U(dp[i][pre], dp[i - 1][pre] + A);
                } else {
                    U(dp[i][pre], dp[i - 1][pre] + B);
                }
            }
    // rep (i, n) re0 (pre, n + 1) {
    //     if (dp[i][pre] != tmp)
    //         printf("dp[%lld][%lld] = %lld\n", i, pre, dp[i][pre]);
    // }
    int ans = 1e18;
    for (int pre = 0; pre <= n; pre++)
        U(ans, dp[n][pre]);
    cout << ans << "\n";
}
