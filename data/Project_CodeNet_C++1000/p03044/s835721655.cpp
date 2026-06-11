#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <iomanip>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;
using P = pair<ll, ll>;

int main(){
  ll n;
  cin >> n;
  vector<vector<P>> G(n);
  rep(i, n-1){
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    w %= 2;
    G[u].push_back(P(v, w));
    G[v].push_back(P(u, w));
  }
  vector<ll> dist(n, -1);
  rep(i, n){
    if (dist[i] != -1) continue;
    queue<ll> que;
    que.push(i);
    dist[i] = 0;
    while(!que.empty()){
      ll x = que.front();
      que.pop();
      for(P nx : G[x]){
        if (dist[nx.first] != -1) continue;
        dist[nx.first] = dist[x] + nx.second;
        que.push(nx.first);
      }
    }
  }
  rep(i, n){
    if (dist[i] % 2 == 0) cout << 0 << endl;
    else cout << 1 << endl;
  }
  
  return 0;
}