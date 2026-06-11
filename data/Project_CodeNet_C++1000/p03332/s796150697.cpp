#include <bits/stdc++.h>

using namespace std;
const int maxn = 3e5+10;
const long long mod = 998244353;

int n;
long long a, b, k;
long long fac[maxn];

long long pot(long long a, long long b) {
    if (b == 0) return 1;
    else if (b & 1) return (a * pot(a, b - 1)) % mod;
    else {
        long long out = pot(a, b / 2);
        return (out * out) % mod;
    }
}

long long inv(long long a) {
    return pot(a, mod - 2);
}

long long divi(long long a, long long b) {
    return (a * inv(b)) % mod;
}

long long choose(int n, int k) {
    //printf("choose: %lld %lld %lld\n", fac[n], fac[n - k], fac[k]);
    //if (k > n) return 1;
    return divi(fac[n], (fac[k] * fac[n - k]) % mod);
}

int main() {
    scanf("%d%lld%lld%lld", &n, &a, &b, &k);

    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % mod;

    long long sol = 0;
    for (int i = 0; i <= n; i++) {
        //printf("%lld\n", i);
        if (k >= a * i && (k - a * i) % b == 0) {
            long long j = (k - a * i) / b;
            if (j > n) continue;
            sol += (choose(n, i) * choose(n, (int)j)) % mod, sol %= mod;
            //printf("%d %d -> %lld\n", i, j, (choose(n, i) * choose(n, j)) % mod);
        }
    }
    printf("%lld", sol);
    return 0;
}
