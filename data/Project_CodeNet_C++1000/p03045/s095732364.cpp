#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > G;
vector<bool> visited;

void dfs(int now){
  visited[now] = true;
  for(auto next : G[now]){
    if(!visited[next]) dfs(next);
  }
}

signed main(){
  int n, m; scanf("%d %d", &n, &m);
  G.resize(n);
  visited.resize(n, false);
  for(int i = 0; i < m; i++){
    int x, y, z; scanf("%d %d %d", &x, &y, &z);
    --x; --y;
    G[x].push_back(y); G[y].push_back(x);
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      dfs(i);
      ans++;
    }
  }
  printf("%d\n", ans);
}