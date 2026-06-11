#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

Graph g;

vector<int> color; 
bool dfs(int v, int c = 0){
  color[v] = c;
  for(auto nv : g[v]){
    if(color[nv] != -1){ 
      if(color[nv] == c)return false; 
    }
    else if(!dfs(nv, 1 - c))return false;
  }

  return true;
}

int main(){
  ll n, m;
  cin >> n >> m;

  g.resize(n);
  for(int i = 0; i < m; ++i){
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  color.assign(n, -1);
  if(dfs(0)){
    int whiteCount = 0;
    for(int i = 0; i < n; ++i){
      if(color[i] == 0)++whiteCount;
    }
    cout << whiteCount * (n - whiteCount) - m << endl;
  }
  else cout << n * (n - 1) / 2 - m << endl;
}
