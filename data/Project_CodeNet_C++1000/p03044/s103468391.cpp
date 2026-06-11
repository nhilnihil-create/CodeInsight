#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

vector<int> ans;
vector<vector<pair<int, ll>>> vec;
vector<int> visited;

void dfs(int node, ll dis){
  if(dis % 2 == 0) ans[node] = 0;
  else ans[node] = 1;
  visited[node] = 1;
  for(auto p : vec[node]){
    if(visited[p.first] == 0) dfs(p.first, dis+p.second);
  }
}

int main(){
  int n;
  cin >> n;
  rep(i, n) ans.push_back(0);
  rep(i, n) visited.push_back(0);
  rep(i, n) vec.push_back(vector<pair<int, ll>>());
  rep(i, n-1){
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--; v--;
    vec[u].push_back(make_pair(v, w));
    vec[v].push_back(make_pair(u, w));
  }
  dfs(0, 0);
  rep(i, n) cout << ans[i] << endl;
}
      
      