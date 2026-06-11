#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)

int main(){
    int n;
    cin >> n;
    ve<ll> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) a[i] -= i+1;
    sort(a.begin(), a.end());
    ll b;
    if(n%2==0) b = (a[n/2] + a[n/2-1])/2;
    else b = a[n/2];
    ll ans = 0;
    rep(i,n) ans += abs(a[i]-b);
    cout << ans << endl;
    return 0;
}
