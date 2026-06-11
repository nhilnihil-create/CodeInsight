#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
#define MOD (ll)(1e9+7)
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;


signed main(){
    ll h,w;
    cin >> h >> w;
    ll d[10][10] = {};
    ll a[h][w] = {};
    ll ans = 0;

    rep(i,0,10) rep(j,0,10) cin >> d[i][j];

    rep(k,0,10) rep(i,0,10) rep(j,0,10) d[i][j] = min(d[i][j],d[i][k] + d[k][j]);

    rep(i,0,h) rep(j,0,w){
        cin >> a[i][j];
        if(a[i][j] != -1) ans += d[a[i][j]][1]; 
    }

    cout << ans << endl;

    return 0;
}