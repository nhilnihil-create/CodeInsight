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
    ll n;
    cin >> n;
    ll ans = 0;
    ll v[n],c[n];
    rep(i,0,n){
        cin >> v[i];
    }
    rep(i,0,n){
        cin >> c[i];
        if(v[i] - c[i] >= 0) ans += v[i] - c[i];
    }
    cout << ans << endl;

    return 0;
}
