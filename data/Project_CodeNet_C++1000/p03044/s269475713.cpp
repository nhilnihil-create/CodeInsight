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
#define fi first
#define se second
 
// rep(i, 0, sz(v)) cout << v[i] << " \n"[i==sz(v)-1];
 
////////////////////////////////////////////////////////
ll n;
Vp adj[100001];
ll col[100001];

void bfs(){
    queue<ll> qu;
    qu.push(0);
    Vl d(n, INF);
    d[0] = 0;
    while(!qu.empty()){
        ll u = qu.front(); qu.pop();
        rep(i, 0, sz(adj[u])){
            ll v = adj[u][i].first;
            ll dist = adj[u][i].second;
            if(d[v]!=INF) continue;
            qu.push(v);
            d[v] = d[u] + dist;
        }
    }
    rep(i, 0, n) co((d[i]%2==0 ? 1 : 0));
}

int main() {
    cin >> n;
    rep(i, 0, n-1){
        ll u, v, w; cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    bfs();

    return 0;
}
 