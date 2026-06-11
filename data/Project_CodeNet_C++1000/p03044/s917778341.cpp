#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;
const double pi = acos(-1.0);

using Graph = vector<vector<pair<int, ll>>>;

Graph g;
vector<bool> seen;
vector<int> color;

void dfs(int v, int c) {
    seen[v] = true;
    color[v] = c;
    for(auto x : g[v]) {
        if(seen[x.first]) continue;
        if(x.second % 2 == 0) dfs(x.first, c);
        else dfs(x.first, 1-c);
    }
}

int main() {
    int n; cin >> n;
    g.resize(n);
    rep(i, n-1) {
        int u, v; ll w; cin >> u >> v >> w; u--; v--;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    seen.resize(n, false);
    color.resize(n, 0);
    dfs(0, 0);
    rep(i, n) cout << color[i] << endl;
}
