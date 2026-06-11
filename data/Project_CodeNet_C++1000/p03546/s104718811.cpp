#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define ALL(a) (a).begin(),(a).end()
 
using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
 
const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 60;
const int INF = 1e9 + 7;

int main(){
    ll h, w;
    cin >> h >> w;

    ll mp[10][10];
    rep(i, 10)rep(j, 10)cin >> mp[i][j];

    rep(k, 10)rep(i, 10)rep(j, 10){
        mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
    }

    ll ans = 0;
    rep(i, h)rep(j, w){
        ll a;
        cin >> a;
        if(a >= 0)ans += mp[a][1];
    }

    cout << ans << endl;
}