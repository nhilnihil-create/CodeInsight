#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (long i = long(s); i < long(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long;
using namespace std;

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> x(n), y(n), z(n); rep(i,n) cin >> x[i] >> y[i] >> z[i];

    ll ans = 0;
    loop(i,-1,2) loop(j,-1,2) loop(k,-1,2){
        if(i==0 || j==0 || k==0) continue;
        vector<ll> data(n); rep(l,n) data[l] = x[l]*i + y[l]*j + z[l]*k;
        sort(all(data));
        ll count = 0;
        rep(l,m) count += data[n-1-l];
        if(ans < count) ans = count;
    }
    cout << ans << endl;
}