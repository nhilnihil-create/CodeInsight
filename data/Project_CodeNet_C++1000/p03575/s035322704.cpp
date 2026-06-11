#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

void print(Vl vec){
    rep(i, 0, sz(vec)){
        if(i) cout << " ";
        cout << vec[i];
    }
    coel;
}

////////////////////////////////////////////////////////

vector<Vl> G;
ll n, m;
ll color[55];
const int white = 0, black = 1;

void bfs(ll a, ll b){
    queue<ll> qu;
    qu.push(1);
    color[1] = black;
    while(!qu.empty()){
        ll t = qu.front(); qu.pop();
        color[t] = black;
        rep(i, 0, G[t].size()){
            if(a == t && b == G[t][i]) continue;
            if(b == t && a == G[t][i]) continue;
            if(color[G[t][i]]) continue;
            qu.push(G[t][i]);
            color[G[t][i]] = black;
        }
    }
}

int main() {
    cin >> n >> m;
    G.resize(n+1);
    vector<pair<ll, ll>> M(m);
    rep(i, 0, m){
        ll a, b; cin >> a >> b;
        M[i].fi = a, M[i].se = b;
        G[b].push_back(a);
        G[a].push_back(b);
    }
    ll ans = 0;
    rep(i, 0, m){
        Rep(i, 1, n) color[i] = white;
        bfs(M[i].fi, M[i].se);
        Rep(i, 1, n){
            if(color[i] == white){
                ans++;
                break;
            }
        }
    }
    co(ans);

    return 0;
}
