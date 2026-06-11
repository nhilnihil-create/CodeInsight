#include <iostream>
#include <cstdio>
using namespace std;

const int mod = 998244353, maxn = 3000010;
long long n, a, b, k, ans;

inline long long fpow(long long a, long long x){
    long long ret = 1;
    while (x) {
        if (x & 1) ret = ret * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return ret;
}

long long inv[maxn], fac[maxn];

inline void init() {
	fac[0] = 1;
	for (int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i % mod;
    inv[maxn - 1] = fpow(fac[maxn - 1], mod - 2);
    for (int i = maxn - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}

long long C(long long n, long long m) {
    if (n < m) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main() {
	init();
	scanf ("%lld %lld %lld %lld", &n, &a, &b, &k);
	for(int i = 0; i <= n; i++) {
        if ((k - a * i < 0) || ((k - a * i) % b != 0)) continue;
        long long x = (k - a * i) / b;
        if (x > n) continue;
        ans = (ans + C(n, i) * C(n, x) + mod) % mod;
    }
    printf ("%lld\n", ans);
	return 0;
}