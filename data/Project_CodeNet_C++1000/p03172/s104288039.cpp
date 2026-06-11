#include <bits/stdc++.h>


using namespace std;

const int MOD = 1E9 + 7;
int main() {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<long long> dp(k + 1);
        dp[0] = 1;
        for (int i = 0, w; i < n; i++) {
                scanf("%d", &w);
                vector<long long> pre(k + 2);
                for (int a = k; a >= 0; a--) {
                        (pre[a + 1] += dp[a]) %= MOD;
                        (pre[a + min(w, k - a) + 1] -= dp[a] - MOD) %= MOD;
                }
                for (int j = 0; j <= k; j++) {
                        if (j) (pre[j] += pre[j - 1]) %= MOD;
                        (dp[j] += pre[j]) %= MOD;
                }
        }

        printf("%lld\n", dp[k]);
}