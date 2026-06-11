#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
ll modpow(ll a, ll n, ll mod = MOD) {
    ll res = 1;
    while(n > 0) {
        if(n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main() {
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> cum(n + 1, 0), cumA(n + 1, 0), cumC(n + 1, 0);
    for(int i = 0; i < n; i++) {
        cum[i + 1] = cum[i] + (s[i] == '?');
        cumA[i + 1] = cumA[i] + (s[i] == 'A');
        cumC[i + 1] = cumC[i] + (s[i] == 'C');
    }
    ll ans = 0;
    for(int i = 1; i < n - 1; i++) {
        if(s[i] == 'A' || s[i] == 'C') {
            continue;
        }
        ll tmp = 0;
        ll a = cumA[i];
        ll c = cumC[n] - cumC[i + 1];
        ll l = cum[i];
        ll r = cum[n] - cum[i + 1];
        //(ABC)を作る
        tmp += ((a * c) % MOD) * modpow(3, l + r);
        tmp %= MOD;
        //(AB?)を作る
        tmp += ((a * r) % MOD) * modpow(3, l + r - 1);
        tmp %= MOD;
        //(?BC)を作る
        tmp += ((l * c) % MOD) * modpow(3, l + r - 1);
        tmp %= MOD;
        //(?B?)を作る
        tmp += ((l * r) % MOD) * modpow(3, l + r - 2);
        tmp %= MOD;
        ans += tmp;
        ans %= MOD;
    }
    cout << ans << endl;
}
