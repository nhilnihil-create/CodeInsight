#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)

int main(){
    ll n,m;
    cin >> n >> m;
    ve<ll> a(n);
    rep(i,n) cin >> a[i];
    ve<ll> s(n+1);
    map<ll,ll> mo;
    s[0] = 0;
    rep(i,n){
        s[i+1] = s[i] + a[i];
        s[i+1] %= m;
        mo[s[i+1]]++;
    }
    mo[0]++;
    ll ans = 0;
    for(P x: mo){
        ll cnt = x.second;
        ans += (cnt-1) * cnt / 2;
    }
    cout << ans << endl;
    return 0;
}
