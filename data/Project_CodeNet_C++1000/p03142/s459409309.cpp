#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e5 + 5;

int N, M;
int par[maxn], deg[maxn];
vector<int> adj[maxn];

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  if (fopen("A.INP", "r")){
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  }
  cin >> N >> M;
  for (int i = 1; i <= N + M - 1; ++i){
    int u, v; cin >> u >> v;
    adj[u].pb(v); ++deg[v];
  }
  vector<int> topo;
  for (int i = 1; i <= N; ++i){
    if (deg[i] == 0){
      topo.pb(i);
    }
  }
  int cur = 0;
  while (cur < topo.size()){
    int u = topo[cur++];
    for (int v : adj[u]){
      --deg[v];
      if (deg[v] == 0){
        par[v] = u;
        topo.pb(v);
      }
    }
  }
  for (int i = 1; i <= N; ++i) cout << par[i] << '\n';
}
