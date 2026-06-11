#include <bits/stdc++.h>

#define int long long

const int MAXN = 4e5;
const int MOD = 998244353;

int fac[MAXN + 100];
int inv[MAXN + 100];

int pow(int base, int k, int mod) {
    int ret = 1;
    while (k) {
        if (k & 1) ret = (ret * base) % mod;
        base = (base * base) % mod, k >>= 1;
    }
    return ret;
}

void init() {
    fac[0] = fac[1] = inv[0] = 1;
    for (int i = 2; i <= MAXN; i++) fac[i] = (fac[i - 1] * i) % MOD;
    for (int i = 1; i <= MAXN; i++) inv[i] = pow(fac[i], MOD - 2, MOD);
    // for (int i = 1; i <= 10; i++)
    //     printf("inv(%lld!) is %lld, fac(%lld) is %lld\n", i, inv[i], i, fac[i]);
}

int C(int n, int m, int mod) {
    if (m < n) return 0;
    // printf("C(%lld, %lld) is %lld\n", n, m,
    //        (inv[n] * ((inv[m - n] * fac[m]) % mod)) % mod);
    return (inv[n] * ((inv[m - n] * fac[m]) % mod)) % mod;
}

signed main() {
    init();
    int n, a, b, k;
    scanf("%lld%lld%lld%lld", &n, &a, &b, &k);

    int ans = 0;

    int cnt_b;
    for (int cnt_a = 0; cnt_a <= n; cnt_a++) {
        cnt_b = (k - cnt_a * a) / b;
        if (cnt_b * b + cnt_a * a == k && cnt_b <= n && cnt_b >= 0)
            ans = (ans + C(cnt_a, n, MOD) * C(cnt_b, n, MOD)) % MOD;
    }

    printf("%lld\n", ans);
}