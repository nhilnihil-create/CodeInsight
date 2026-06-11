#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 300005;
const int MOD = 998244353;

llint n, a, b, k;
llint f[MAXN], inv[MAXN];

llint pot (llint b, llint e) {
    if (e == 0) return 1;
    if (e & 1) {
        return pot(b, e-1) * b % MOD;
    } else {
        llint t = pot(b, e/2);
        return t*t%MOD;
    }
}

void precompute () {
    f[0] = 1;
    inv[0] = 1;
    for (int i=1; i<=n; i++) {
        f[i] = f[i-1] * i % MOD;
        inv[i] = pot(f[i], MOD-2);
    }
}

llint nck (llint x, llint y) {
    return f[x] * inv[y] % MOD * inv[x-y] % MOD;
}

int main () {
    cin >> n >> a >> b >> k;
    llint p = n, c;
    precompute();
    llint sol = 0;
    for (c=0; c<=n; c++) {
        while (c*a + p*b > k && p >= 0) {
            p--;
        }
        p = max(p, 0LL);
        if (c*a + p*b == k) {
            sol = (sol + nck(n, c) * nck(n, p)) % MOD;
        }
    }
    cout << sol;
    return 0;
}
