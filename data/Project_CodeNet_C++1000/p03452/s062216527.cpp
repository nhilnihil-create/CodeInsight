#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;
typedef tuple<int,int,int> T;

typedef struct Edge {
    ll to, cost;
} Edge;

vector<vector<Edge>> g;
bool ok = true;
ll dist[252525];
bool vi[252525];

void dfs(int x, ll d) {
    if (vi[x]) return;
    vi[x] = true;
    dist[x] = d;
    for (auto &&e: g[x]) dfs(e.to,d+e.cost);
    return;
}

int main(int argc, char const *argv[]) {
    int n,m;
    cin >> n >> m;
    vector<ll> l(m),r(m),d(m);
    g.resize(n);

    REP(i,m) {
        cin >> l[i] >> r[i] >> d[i];
        --l[i],--r[i];
        g[l[i]].push_back({r[i],d[i]});
        g[r[i]].push_back({l[i],-1ll*d[i]});
    }

    memset(dist,0,sizeof(dist));
    memset(vi,0,sizeof(vi));

    for (int i = 0; i < n; ++i) dfs(i, 0);
    

    REP(i,m) {
        if (dist[r[i]]-dist[l[i]] != d[i]) ok = false;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}