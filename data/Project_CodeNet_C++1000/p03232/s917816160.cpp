#include <iostream>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007LL;

ll moddiv(ll a, ll b) {
    ll t = MOD-2;
    while(t) {
        if(t & 1) {
            a *= b;
            a %= MOD;
        }
        b *= b;
        b %= MOD;
        t >>= 1;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    ll a[n];
    for(int i=0;i<n;++i) cin >> a[i];

    ll fact = 1LL;
    for(ll i=2;i<=n;++i) (fact *= i) %= MOD;

    ll ra[n+1];
    ra[0] = 0;
    for(ll i=1;i<=n;++i) {
        ra[i] = (ra[i-1] + moddiv(fact, i)) % MOD;
    }


    ll ans = 0LL;
    for(int i=0;i<n;++i) {
        ans += (a[i] * (ra[i+1] + ra[n-i] - ra[1] + MOD) % MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}