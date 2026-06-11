#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

#define ll long long

ll bin(ll x, ll n, ll MOD) {
    ll ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}

inline ll get_inv(ll x, ll p) { return bin(x, p - 2, p); }

ll extended_euclid(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        ll d = extended_euclid(b, a % b, x, y);
        ll xtemp = x, ytemp = y;
        x = ytemp;
        y = xtemp - (a / b) * ytemp;
        return d;
    }
}

#define maxn 300005
ll invf[maxn], fac[maxn] = {1};
#define mod  998244353

void fac_inv_init(ll n, ll p) {
    for (long long i = 1; i < n; i++) {
        fac[i] = i * fac[i - 1] % p;
    }
    invf[n - 1] = bin(fac[n - 1], p - 2, p);
    for (long long i = n - 2; i > -1; i--)
        invf[i] = invf[i + 1] * (i + 1) % p;

}

inline ll C(ll n, ll m) {
    return n < m || m < 0 ? 0 : fac[n] * invf[m] % mod * invf[n - m] % mod;
}

bool solve(ll a, ll b, ll c, ll &x, ll &y) {
    int n = extended_euclid(a, b, x, y);
    if (c % n) return false;
    int k = c / n;
    x *= k;
    y *= k;
    return true;
}


int main() {
    long long n, a, b, k;
    scanf("%lld%lld%lld%lld", &n, &a, &b, &k);
    long long res = 0;
    fac_inv_init(300005, mod);
    for (long long x = 0; x <= n; x++) {
        if (k - (x * a) >= 0 && (k - (x * a)) % b == 0 && (k - a * x) / b <= n) {
            res = (res + C(n, x) * C(n, (k - a * x) / b) % mod) % mod;
        }
    }
    printf("%lld\n", res);
}
