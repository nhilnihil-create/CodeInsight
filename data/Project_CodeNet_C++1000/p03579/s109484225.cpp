#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;
vector<vector<ll>> edge;
vector<ll> can_visit;

void dfs(ll cur){

  for (int i = 0; i < edge[cur].size(); i++){
    ll u = edge[cur][i];

    if (can_visit[cur] & 1){
      if (!((can_visit[u] >> 1) & 1)){
        can_visit[u] |= 2;
        dfs(u);
      }
    }
    if ((can_visit[cur] >> 1) & 1){
      if (!(can_visit[u] & 1)){
        can_visit[u] |= 1;
        dfs(u);
      }
    }
  }
}

int main(void){
  ll n, m;
  cin >> n >> m;
  edge = vector<vector<ll>> (n, vector<ll>(0));
  for (int i = 0; i < m; i++){
    ll x, y;
    cin >> x >> y;
    
    x--; y--;
    edge[x].emplace_back(y);
    edge[y].emplace_back(x);
  }
  
  can_visit = vector<ll>(n, 0);
  can_visit[0] = 1;

  dfs(0);
  
  ll e = 0, o = 0;
  for (int i = 0; i < n; i++){
    if (can_visit[i] == 1)
      e++;
  }
  for (int i = 0; i < n; i++){
    if (can_visit[i] == 2)
      o++;
  }

  cout << n*(n-1)/2 - e*(e-1)/2 - o * (o-1)/2 - m << endl;

  return 0;
}
