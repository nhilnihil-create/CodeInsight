#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> ruiseki(n+1, 0);
    rep(i,n){
        ruiseki[i+1] = ruiseki[i] + a[i];
    }
    map<ll, ll> mp;
    for(i = 0;i <= n;++i){
        ++mp[ruiseki[i]];
    }
    ll ans = 0;
    for(auto x:mp){
        ll num = x.second;
        ans += num*(num-1)/2;
    }
    cout << ans << endl;

    return 0;
}