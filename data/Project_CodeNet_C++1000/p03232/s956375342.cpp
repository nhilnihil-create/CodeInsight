#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair
#define int         int64_t

using namespace std;

const int N = int(3e5) + 7;
const int mod = int(1e9) + 7;

int n, a[N], res, fac, cur, inv[N];

int Pow(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = res * x % mod;
        x = x * x % mod; y >>= 1;
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n; fac = 1;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i]; fac = fac * i % mod;
        inv[i] = inv[i - 1] + Pow(i, mod - 2);
        if(inv[i] >= mod) inv[i] -= mod;
    } int res = 0;
    for(int i = 1; i <= n; ++i) {
        res += ((inv[i] + inv[n - i + 1] - 1) * a[i] % mod);
        if(res >= mod) res -= mod;
    }
    cout << res * fac % mod;
}
