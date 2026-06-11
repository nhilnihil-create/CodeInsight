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

using Graph = vector<vector<int>>;

bool dfs(Graph &g, int v, int cnt, vector<int> &color) {
    color[v] = cnt;
    for(auto x : g[v]) {
        if(color[x] != -1) {
            if(color[x] == cnt) return false;
            continue;
        }
        if(!dfs(g, x, 1-cnt, color)) return false;
    }
    return true;
}

int main() {
    ll n, m; cin >> n >> m;
    Graph g(n);
    vector<int> color(n, -1);
    rep(i, m) {
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool fl = true;
    rep(i, n) if(color[i] == -1) if(!dfs(g, i, 0, color)) fl = false;
    ll a = 0;
    rep(i, n) if(color[i] == 0) a++;
    cout << (fl ? a*(n-a)-m : n*(n-1)/2-m) << endl;
}
