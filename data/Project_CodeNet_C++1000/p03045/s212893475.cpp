#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

vector<vector<int>> g;
vector<int> ans;

void dfs(int now){
  ans[now] = 1;
  for(int v: g[now]){
    if(ans[v]) continue;
    dfs(v);
  }
}

int main(){
  int n,m; cin >> n >> m;
  g.resize(n);
  ans.resize(n, 0);
  for(int i = 0; i < m; i++){
    int x,y,z; cin >> x >> y >> z;
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  ll res = 0;
  for(int i = 0; i < n; i++){
    for(int v: g[i]){
      if(ans[v]) continue;
      res++;
      dfs(v);
    }
  }

  for(int i = 0; i < n; i++){
    if(!ans[i]) res++;
  }
  cout << res << endl;
  return 0;
}
