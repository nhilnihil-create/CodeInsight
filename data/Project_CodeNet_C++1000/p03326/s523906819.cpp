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
    
    ve<ve<ll>> a(4,ve<ll>(n));
    rep(i,n){
        ll x,y,z;
        cin >> x >> y >> z;
        a[0][i] = x+y+z;
        a[1][i] = x+y-z;
        a[2][i] = x-y+z;
        a[3][i] = x-y-z;
    }
    rep(i,4)sort(a[i].begin(), a[i].end());
    
    ll ans = 0;
    rep(i,4){
        ll me1 = 0, me2 = 0;
        rep(j,m){
            me1 += a[i][j];
            me2 += a[i][n-1-j];
        }
        ans = max(ans,abs(me1));
        ans = max(ans,abs(me2));
    }
    cout << ans << endl;
    return 0;
}
