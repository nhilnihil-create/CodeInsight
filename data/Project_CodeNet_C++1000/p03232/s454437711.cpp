#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
 
const double EPS = 1e-10;
const ll INF = 100000000;
const ll MOD = 1000000007;

ll n;
ll a[100001];
ll ans = 0;
ll sum[100001];
ll kai[100001];

inline ll add (ll x, ll y) {
    return (x+y)%MOD;
}

ll mod_pow (ll x, ll y) {
    ll ret = 1;
    while (y) {
        if (y&1) ret = ret * x % MOD;
        x = x * x % MOD;
        y /= 2;
    }
    return ret;
}

int main() {
    cin >> n;
    rep(i,n) cin >> a[i];
    kai[0] = 1;
    for (ll i = 1; i <= n; i++) kai[i] = kai[i-1] * i % MOD;
    rep(i,n) {
        if (i == 0) sum[i] = a[i];
        else sum[i] = add(sum[i-1], a[i]);
    }
    ans = add(ans, sum[n-1]);
    ans = ans*kai[n]%MOD;
    {
        ll acc = 0;
        rep(i,n-1) {
            acc = add(acc, a[i]);
            ll tmp = acc * kai[n] % MOD;
            tmp = tmp * mod_pow(i+2, MOD-2) % MOD;
            ans = add(ans, tmp);
        }
    }
    {
        ll acc = 0;
        for (int i = n-1; i >= 1; i--) {
            acc = add(acc, a[i]);
            ll tmp = acc * kai[n] % MOD;
            tmp = tmp * mod_pow(n-i+1, MOD-2) % MOD;
            ans = add(ans, tmp);
        }
    }
    {
        ll acc = 0;
        ll l = 0, r = n-2;
        for (int i = 1; i <= n-2; i++) {
            acc = (acc + sum[r] - sum[l] + MOD) % MOD;
            ll tmp = acc * kai[n] * 2LL % MOD;
            tmp = tmp * mod_pow(i+2, MOD-2) % MOD;
            tmp = tmp * mod_pow(i+1, MOD-2) % MOD;
            ans = add(ans, tmp);

            l++; r--;
        }
    }
    cout << ans << endl;
}

