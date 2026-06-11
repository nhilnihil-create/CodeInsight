# include <bits/stdc++.h>
# define rep(i, n) for(ll i = 0; i < (n); ++i)
# define reps(i, n) for(ll i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(ll i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(ll i=((int)(n)); i>0; --i)
# define ll long long
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define P pair<int, int>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll lmax(ll a, ll b){if(a>= b) return a;return b;}
ll lmin(ll a, ll b){if(a>= b) return b;return a;}
static const ll INF = 1e18;

struct Edge {
    int to;     // 辺の行き先
    ll weight; // 辺の重み
    Edge(int t, int w) : to(t), weight(w) { }
};

using Graph = vector<vector<Edge>>;

Graph g;
vector<int> ans;

void dfs(int v){
  for(auto next_v : g[v]){
    if(ans[next_v.to] != -1) continue;
    if(next_v.weight == 1){
      if(ans[v] == 0) ans[next_v.to] = 1;
      else ans[next_v.to] = 0;
    } else {
      if(ans[v]==0) ans[next_v.to] = 0;
      else ans[next_v.to] = 1;
    }
    dfs(next_v.to);
  }
}

int main() {
  int n; cin >> n;
  g.resize(n);
  vector<int> u(n-1), v(n-1);
  rep(i, n-1){
    ll w;
    cin >> u[i] >> v[i] >> w;
    w %= 2;
    --u[i];--v[i];
    g[u[i]].pb(Edge(v[i], w));
    g[v[i]].pb(Edge(u[i], w));
  }

  ans.resize(n);
  rep(i, n) ans[i] = -1;
  ans[0] = 1;

  dfs(0);

  rep(i, n){
    cout << ans[i] << endl;
  }
}
