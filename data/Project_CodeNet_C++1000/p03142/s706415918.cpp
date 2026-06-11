#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;

using namespace std;

vector<int> ve[MAXN];
int par[MAXN];
bool notroot[MAXN], vis[MAXN];
vector<int> topo;

void dfs(int u) {
  vis[u] = 1;
  for (int v : ve[u])
    if (!vis[v])
      dfs(v);
  topo.pb(u);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int r = 1;
  for (int i = 0; i < n-1+m; i++) {
    int u, v;
    cin >> u >> v;
    ve[u].pb(v);
    notroot[v] = 1;
    while (notroot[r])
      r++;
  }
  par[0] = 0;
  dfs(r);
  reverse(all(topo));
  for (int k : topo)
    for (int v : ve[k])
      par[v] = k;
  for (int i = 1; i <= n; i++)
    cout << par[i] << '\n';
  return 0;
}