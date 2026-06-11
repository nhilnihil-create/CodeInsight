#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

Graph G;
vector<bool> seen;
int cnt = 0;

void dfs(int v){
  seen[v] = true;
  for(int nv: G[v]){
    if(seen[nv]) continue;
    dfs(nv);
  }
}
    

int main(){
  int n, m; cin >> n >> m;
  G.resize(n);
  seen.resize(n);
  for(int i = 0; i < m; i++){
    int x, y, z; cin >> x >> y >> z;
    --x; --y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  for(int i = 0; i < n; i++){
    if(seen[i]) continue;
    cnt++;
    dfs(i);
  }
  cout << cnt << endl;
}