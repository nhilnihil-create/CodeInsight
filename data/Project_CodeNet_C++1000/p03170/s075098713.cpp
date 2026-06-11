#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
using namespace std;

const int N = 105, K = 1E5 + 1;
int dp[K], a[N];
int main() {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        dp[0] = 0;
        for (int j = 1; j <= k; j++) {
                for (int i = 1; i <= n; i++) {
                        if (j - a[i] >= 0) dp[j] |= !dp[j - a[i]];
                }
        }
        printf("%s", (dp[k] ? "First" : "Second"));
}