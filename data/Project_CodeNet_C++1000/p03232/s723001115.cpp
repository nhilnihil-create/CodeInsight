#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

typedef long long ll;
const int N = 1e5 + 7;
const ll MOD = 1e9 + 7;

ll inv[N], s[N], a[N];
ll ans, n;

int main() {
#ifdef WYXLOCAL
    freopen("tmp.in", "r", stdin);
    freopen("tmp.out", "w", stdout);
#endif // WYXLOCAL
    scanf("%lld", &n);
    inv[1] = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        if (i != 1) inv[i] = (-inv[MOD%i] * (MOD / i) % MOD + MOD) % MOD;
        // printf("%lld ", inv[i]);
        s[i] = (s[i-1] + inv[i]) % MOD; // 算前缀和的时候也要取模啊。
    }
    for (int i = 1; i <= n; ++i) {
        ans = (ans + a[i] * (s[i] + s[n-i+1] - 1) % MOD) % MOD;
    }
    for (int i = 1; i <= n; ++i) {
        ans = 1ll * ans * i % MOD; // 我们算的是期望，但是题目要求算期望的分子。
    }
    std::cout << ans << '\n';
    return 0;
}
