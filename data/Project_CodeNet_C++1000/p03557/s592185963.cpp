#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

int main(){
    int n;
    cin >> n;
    ve<int> a(n),b(n),c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll ans=0;
    rep(i,n){
        ll memo;
        memo = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        memo *= n-(upper_bound(c.begin(), c.end(), b[i])-c.begin());
        ans += memo;
    }
    cout << ans << endl;
}