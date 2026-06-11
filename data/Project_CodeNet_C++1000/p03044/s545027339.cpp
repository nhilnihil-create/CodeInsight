#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N;
ll color[100010];
vector<pll> adj[100010];

void dfs(ll i, ll d, ll c){
    if(color[i] != -1) return;
    if(d % 2 == 0) color[i] = c;
    else color[i] = 1 - c;
    for(auto p : adj[i]){
        dfs(p.first, p.second, color[i]);
    }
}

signed main(){
    cin >> N;
    ll u, v, w;
    REP(i, N - 1){
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back(pll(v, w));
        adj[v].push_back(pll(u, w));
    }
    REP(i, N) color[i] = -1;
    dfs(0, 0, 0);
    REP(i, N) PRINT(color[i]);
    return 0;
}