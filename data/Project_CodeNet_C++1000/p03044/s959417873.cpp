#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
using ll = long long;

int n;
vector<vector<pair<int,int>>> edge(MAX);
vector<int> vs(MAX);

void dfs(int v, int color, int parent)
{
  for (auto e : edge[v]) {
    int to = e.first, dist = e.second;
    
    if (to == parent) continue;
    
    int next_color;

    if (dist % 2 == 0) next_color = color;
    else next_color = color ^ 1;
    vs[to] = next_color;

    dfs(to, next_color, v);
  }
}

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n-1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;

    edge[u-1].emplace_back(v-1, w);
    edge[v-1].emplace_back(u-1, w);
  }

  dfs(0, 0, -1);
  for (int i = 0; i < n; ++i) cout << vs[i] << '\n';

  return (0);
}
