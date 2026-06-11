#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>

typedef long long ll;

const int MAXN = 3e5 + 7;
const ll HA = 998244353;

ll fac[MAXN], inv[MAXN];

ll fp(ll a, ll b = HA - 2) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % HA;
        a = a * a % HA, b >>= 1;
    }
    return ret;
}

void init() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= 300000; i++) fac[i] = fac[i - 1] * i % HA;
    inv[300000] = fp(fac[300000]);
    for (int i = 300000 - 1; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % HA;
    // for (int i = 1; i <= 30; i++) {
    //     printf("%lld\n", fac[i]);
    // }
}

ll C(ll n, ll m) {
    if (n < m) return 0;
    return fac[n] * inv[m] % HA * inv[n - m] % HA;
}

int main(int argc, char *argv[]) {
    init();
    int n, A, B;
    ll k, ans = 0;
    scanf("%d %d %d %lld", &n, &A, &B, &k);
    for (int i = 0; i <= n; i++) {
        if ((k - 1ll * A * i) % B) continue;
        if ((k - 1ll * A * i) < 0) continue;
        ll b = (k - 1ll * A * i) / B;
        if (b > n) continue;
        // printf("i = %d, b = %lld\n", i, b);
        ans = (ans + C(n, i) * C(n, b) % HA + HA) % HA;
    }
    printf("%lld\n", ans);
} 