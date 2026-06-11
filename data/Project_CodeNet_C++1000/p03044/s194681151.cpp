#include <bits/stdc++.h>
using namespace std;

vector<int> color;

void dfs(int v, int dis, vector<vector<pair<int, int>>> &G){
  if(dis % 2 == 0) color.at(v) = 0;
  else color.at(v) = 1;
  
  for(auto k: G.at(v)){
    int nv = k.first;
    int tmp = k.second;
    if(color.at(nv) != -1) continue;
    dfs(nv, dis + tmp, G);
  }
}

int main(){
  int n; cin >> n;
  vector<vector<pair<int, int>>> G(n);
  for(int i = 0; i < n-1; i++){
    int u, v, w; cin >> u >> v >> w;
    u--; v--;
    G.at(u).push_back({v, w});
    G.at(v).push_back({u, w});
  }
  color.resize(n, -1);
  color.at(0) = 0;
  dfs(0, 0, G);
  for(int a: color) cout << a << endl;
}