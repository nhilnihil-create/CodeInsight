#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 3e5 + 10, mod = 998244353;
ll fact[N], factRev[N];

ll sum(ll a, ll b) {
    return ((1LL * a + b) % mod + mod) % mod;
}

ll mul(ll a, ll b) {
    return ((1LL * a * b) % mod + mod) % mod;
}

ll pw(ll n, ll m) {
    ll res = 1, tmp = n;
    while (m) {
        if (m & 1)
            res = mul(res, tmp);
        tmp = mul(tmp, tmp);
        m >>= 1;
    }
    return res;
}

ll c(ll n, ll m) {
    if (m > n)
        return 0;
    return mul(fact[n], mul(factRev[m], factRev[n - m]));
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    fact[0] = 1;
    for (ll i = 1; i <= n; i++)
        fact[i] = mul(fact[i - 1], i);
    factRev[n] = pw(fact[n], mod - 2);
    for (ll i = n - 1; ~i; i--)
        factRev[i] = mul(factRev[i + 1], i + 1);
    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        if (a * i <= k && (k - a * i) % b == 0 && (k - a * i) / b <= n) {
            int y = (k - a * i) / b;
            ans = sum(ans, mul(c(n, i), c(n, y)));
        }
    }
    cout << ans << "\n";
    return 0;
}