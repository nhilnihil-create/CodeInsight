#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define LL long long

using namespace std;

const LL MOD = 998244353ll, maxn = 3e5 + 5;
LL N, A, B, K, ans;
LL fac[maxn], inv[maxn], ifac[maxn];

LL C(LL n, LL m) {
    return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%lld%lld%lld%lld", &N, &A, &B, &K);
    if (!K) { printf("1\n"); return 0; }
    inv[1] = fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= N; i++) {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
        ifac[i] = ifac[i-1] * inv[i] % MOD;
    }
    for (int i = 0; i <= N && i <= K / A; i++) 
        if ((K - i * A) % B == 0 && (K - i * A) / B <= N) 
            ans += C(N, i) * C(N, (K-i*A)/B) % MOD,
            ans %= MOD;
    printf("%lld\n", ans);
    return 0;
}