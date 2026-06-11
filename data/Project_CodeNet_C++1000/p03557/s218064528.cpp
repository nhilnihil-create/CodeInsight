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
    sort(b.rbegin(), b.rend());
    sort(c.begin(), c.end());
    ve<ll> sb(n+1);
    sb[0] = 0;
    rep(i,n){
        int k = upper_bound(c.begin(), c.end(),b[i])-c.begin();
        sb[i+1] = sb[i] + n-k;
    }
    ll ans = 0;
    rep(i,n){
        int k = upper_bound(b.rbegin(), b.rend(), a[i])-b.rbegin();
        ans += sb[n-k];
    }
    cout << ans << endl;
}