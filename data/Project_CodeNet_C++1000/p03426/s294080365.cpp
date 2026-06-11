#include <bits/stdc++.h>
using namespace std;  
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define Rep(i, a, b) for(ll i = a; i <= b; i++)
#define repr(i, a, b) for(ll i = b-1; i >= a; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
// const ll INF = 1LL << 60;
const ll INF = 100000000000;
#define pp pair<ll, pair<ll, ll>> 
// #define fi first
// #define se second
 
/*--------------------------------------------------------------------------------

--------------------------------------------------------------------------------*/


int main(){
    ll h, w, d; cin >> h >> w >> d;
    vector<pair<ll, ll>> pos(h*w+1);
    Rep(i, 1, h) Rep(j, 1, w){
        ll a; cin >> a;
        pos[a] = {i, j};
    }
    ll q; cin >> q;
    // d が予め与えられている　→　距離の個数はせいぜい300*300個　→　前処理
    Vl dist(h*w+1, 0);
    Rep(i, 1, d){
        for(ll j = i+d; j <= h*w; j += d){
            ll dis = abs(pos[j].first-pos[j-d].first)+abs(pos[j].second-pos[j-d].second);
            dist[j] = dist[j-d] + dis;
        }
    }
    while(q--){
        ll ans = 0;
        ll l, r; cin >> l >> r;
        co(dist[r]-dist[l]);
    }
    // rep(i, 1, sz(dist)) cout << dist[i] << " ";
    // coel;
    // Rep(i, 1, h*w) cout << i << " : " << pos[i].first << " , " << pos[i].second << endl;

    return 0;
}
