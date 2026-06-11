#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
const int SIZE = 1e5;
vector<bool> color(SIZE);
vector<vector<pair<int, int>>> T(SIZE);
void dfs(int s = 0, int p = -1) {
   for (auto &&i : T[s])
   {
      if (i.first == p)continue;
      if (i.second % 2 == 1){
         color[i.first] = !color[s];
         dfs(i.first,s);
      }
      else{
         color[i.first] = color[s];
         dfs(i.first,s);
      }
   }  
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n; cin >> n;
   rep(i,n-1){
      int u,v,w; cin >> u >> v >> w;
      u--;v--;
      T[u].push_back(make_pair(v,w));
      T[v].push_back(make_pair(u,w));
   }
   dfs();
   rep(i,n)cout << color[i] << '\n';
}