#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int maxn = 200013;

int n;
int c[maxn], dp[maxn], seen[maxn];

signed main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &c[i]);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if (c[i] != c[i + 1]) {
            if (seen[c[i]])
                (dp[i] += dp[seen[c[i]]]) %= mod;
            seen[c[i]] = i;
        }
    }
    printf("%d\n", dp[n]);
}
