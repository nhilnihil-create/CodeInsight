#include <bits/stdc++.h>
#define ODD(n) (2*n+1)
#define OO 1e9
#define EVEN(n) (2*n)
using namespace std;
const int N = 100001;
const int M = 200001;
vector<pair<int, int>> adj[N];
int dist[N];
bool vis[N];
bool dfs(int u){
  vis[u] = 1;
  for(auto el : adj[u]){
    int v = el.first;
    int d = el.second;
    if(!vis[v]){
      dist[v] = dist[u] + d;
      if(!dfs(v))
        return false;
    }else{
      if(dist[u] + d != dist[v]){
//        cout << u << ' ' << v << ' ' << dist[u] << ' ' << dist[v] << endl;
        return false;
      }
    }
  }
  return true;
}
int main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int n, m;
  cin >> n >> m;

  int u, v, d;
  for(int i = 0;i < m;i++){
    cin >> u >> v >> d;
    u--, v--;
    adj[u].push_back({v, -d});
    adj[v].push_back({u, d});
  }
  for(int i = 0;i < n;i++){
    if(!vis[i]){
      if(!dfs(i)){
        cout << "No";
        return 0;
      }
    }
  }
  cout << "Yes";
  return 0;
}
