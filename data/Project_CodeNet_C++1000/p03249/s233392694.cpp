#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 1e5 + 5;

int par[maxn], N, sub[maxn];
pair<ll, int> d[maxn];
ll f[maxn];
vector<int> adj[maxn];
int depth[maxn], sz[maxn];

void dfs(int u = 1, int p = -1)
{
  sz[u] = 1;
  f[1] += depth[u];
  for(int v : adj[u]) if(v != p){
    depth[v] = depth[u] + 1;
    dfs(v, u);
    sz[u] += sz[v];
  }
}

void reroot(int u = 1, int p = -1)
{
  for(int v : adj[u]) if(v != p){
    f[v] = f[u] + N - 2 * sz[v];
    reroot(v, u);
  }
}

bool check(void)
{
  for(int i = 1; i <= N; ++i)
    if(par[i]) adj[par[i]].pb(i), adj[i].pb(par[i]);
  dfs(); reroot();
  for(int i = 1; i <= N; ++i){
    if(f[d[i].se] != d[i].fi) return false;
  }
  return true;
}

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  if(fopen("A.INP", "r")){
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  }
  cin >> N;
  for(int i = 1; i <= N; ++i){
    cin >> d[i].fi;
    d[i].se = i;
    sub[i] = 1;
  }
  sort(d + 1, d + 1 + N);
  for(int i = N; i >= 2; --i){
    int j = lower_bound(d + 1, d + 1 + N, mp(d[i].fi - (N - 2 * sub[d[i].se]), -1)) - d;
    if(i == j) ++j;
    if(d[j].fi != d[i].fi - (N - 2 * sub[d[i].se])){
      cout << -1;
      return 0;
    }
    par[d[i].se] = d[j].se;
    sub[d[j].se] += sub[d[i].se];
  }
  if(!check()){
    cout << -1;
    return 0;
  }
  for(int i = 1; i <= N; ++i){
    if(par[i]) cout << i << ' ' << par[i] << '\n';
  }
}
