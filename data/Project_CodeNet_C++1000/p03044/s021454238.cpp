#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge{int to, cost;};
vector<vector<edge> > G;
vector<int> color;

void dfs(int now, int ago, int depth){
  if(depth % 2 == 0) color[now] = 1;
  else color[now] = 0;
  for(auto next : G[now]){
    if(next.to == ago) continue;
    else dfs(next.to, now, depth + next.cost);
  }
}

signed main(){
  int n; scanf("%d", &n);
  G.resize(n);
  for(int i = 0; i < n - 1; i++){
    int u, v, w; scanf("%d %d %d", &u, &v, &w);
    --u; --v;
    G[u].push_back(edge{v, w}); G[v].push_back(edge{u, w});
  }
  color.resize(n);
  dfs(0, -1, 0);
  for(int i = 0; i < n; i++){
    printf("%d\n", color[i]);
  }
}