#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

ll pow_mod(ll a, ll n, ll p)
{
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res*a%p;
        a = a*a%p;
        n >>= 1;
    }
    return res;
}

int main()
{
    ll i,j;
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> a(n,0);
    vector<ll> l(n,0);
    vector<ll> r(n,0);
    vector<ll> c(n,0);
    if(s[0] == 'A') a[0] = 1;
    if(s[0] == '?') l[0] = 1;
    for(i = 1;i < n;++i){
        a[i] = a[i-1];
        l[i] = l[i-1];
        if(s[i] == 'A') a[i]++;
        if(s[i] == '?') l[i]++;
    }
    if(s[n-1] == 'C') c[n-1] = 1;
    if(s[n-1] == '?') r[n-1] = 1;
    for(i = n-2;i >= 0;--i){
        c[i] = c[i+1];
        r[i] = r[i+1];
        if(s[i] == 'C') c[i]++;
        if(s[i] == '?') r[i]++;
    }
    ll ans = 0;
    const ll MOD = 1e9+7;
    for(i = 1;i <= n-2;++i){
        if(s[i] == 'B' || s[i] == '?'){
            ans += (a[i-1]*pow_mod(3, l[i-1], MOD)%MOD + l[i-1]*pow_mod(3, l[i-1]-1, MOD)%MOD)%MOD*(c[i+1]*pow_mod(3, r[i+1], MOD)%MOD + r[i+1]*pow_mod(3, r[i+1]-1, MOD)%MOD)%MOD;
            ans %= MOD;
        }
    }
    cout << ans << endl;

    return 0;
}