#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

// a * x + b * y == gcd(a, b) なるx, yを計算
// 返り値はgcd(a, b)
template<typename T>
T extgcd(T a, T b, T& x, T& y) {
    T d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1; y = 0;
    }
    return d;
}

ll f[300050], fi[300050];

ll comb(int x, int y) {
    return f[x] * fi[y] % MOD * fi[x - y] % MOD;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll a, b, K;
    cin >> n >> a >> b >> K;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i % MOD;
    }
    {
        ll x, y;
        extgcd(f[n], MOD, x, y);
        fi[n] = (x + MOD) % MOD;
    }
    
    for (int i = n; i > 0; i--) {
        fi[i - 1] = fi[i] * i % MOD;
    }

    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        if ((K - a * i) % b != 0) continue;
        ll j = (K - a * i) / b;
        if (j < 0 || j > n) continue;
        (ans += comb(n, i) * comb(n, j) % MOD) %= MOD;
    }
    cout << ans << endl;
    return 0;
}
