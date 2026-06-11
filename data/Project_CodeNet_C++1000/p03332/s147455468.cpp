#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 3e5+1;
const ll MOD = 998244353;

ll fac[MAX];

void init() {
    fac[0] = 1;
    for (int i=1; i<MAX; ++i) {
        fac[i] = fac[i-1]*i%MOD;
    }
}

ll rep_pow(int n, int p) { // n^p
    if (p==0) {
        return 1;
    }
    if (p%2==0) {
        ll t=rep_pow(n, p/2);
        return t*t%MOD;
    } else {
        return n*rep_pow(n, p-1)%MOD;
    }
}

ll com(int n, int k) {
    if (n<k || n<0 || k<0) {
        return 0;
    }
    return fac[n]*rep_pow(fac[k], MOD-2)%MOD*rep_pow(fac[n-k], MOD-2)%MOD;
}

int main() {
    init();
    ll n, a, b, k; cin >> n >> a >> b >> k;
    ll ans=0;
    for (ll i=0; a*i<=k; ++i) {
        if ((k-a*i)%b!=0) {
            continue;
        }
        ll l=(k-a*i)/b;
        ans+=com(n, i)*com(n, l);
        ans%=MOD;
    }
    cout << ans;
    return 0;
}
