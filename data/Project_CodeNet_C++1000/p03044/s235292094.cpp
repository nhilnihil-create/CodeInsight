#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
vector<pair<int, int> > g[N];
int col[N];

void dfs(int node, int par, int wt){
  
   col[node] = wt % 2;
   for(auto c : g[node]){
      if(c.second == par)
         continue;
      dfs(c.second, node, wt + c.first);
   }
}

int32_t main() 
{
  
  ios::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
  int n;
  cin >> n;
  
  for(int i = 1; i < n; i++){
      int u, v, w;
      cin >> u >> v >> w;
      g[u].push_back({w, v});
      g[v].push_back({w, u});
  }

  dfs(1, 0, 0);

  for(int i = 1; i <= n; i++)
     cout << col[i] << '\n';

  return 0;
}