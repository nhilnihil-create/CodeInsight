#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair
#define int         int64_t

using namespace std;

const int N = int(3e5) + 7;
const int mod = 998244353;

int fac[N], rev[N], n, a, b, k, res, cur, t;

int Pow(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = res * x % mod;
        x = x * x % mod; y >>= 1;
    }
    return res;
}
int nCk(int n, int k) {return fac[n] * rev[k] % mod * rev[n - k] % mod;}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> a >> b >> k;
    fac[0] = rev[0] = 1;
    for(int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
    rev[n] = Pow(fac[n], mod - 2);
    for(int i = n - 1; i > 0; --i) rev[i] = rev[i + 1] * (i + 1) % mod;
    for(int i = 0; i <= n; ++i) {
        if(a * i > k) break;
        cur = k - a * i;
        if(cur % b != 0 || cur / b > n) continue;
        res += nCk(n, i) * nCk(n, cur / b) % mod;
    }
    cout << res % mod;
}
