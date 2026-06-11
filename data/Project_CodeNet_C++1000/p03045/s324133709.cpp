#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

using Graph = vector<vector<ll>>;
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        dfs(G, next_v); // 再帰的に探索
    }
}


int main(){

  ll n,m;
  cin >> n>> m;

  ll x[m],y[m],z[m];
  for(int i=0;i<m;i++)cin >> x[i] >> y[i] >> z[i];

  vector<vector<ll>> G(n);
  for(int i=0;i<m;i++){
    G[x[i]-1].push_back(y[i]-1);
    G[y[i]-1].push_back(x[i]-1);
  }

  int count = 0;
  seen.assign(n, false);
  for (int v = 0; v < n; ++v) {
    if (seen[v]) continue; // v が探索済みだったらスルー
    dfs(G, v); // v が未探索なら v を始点とした DFS を行う
    ++count;
  }

  cout << count << endl;



}