#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
ll Mod = 1000000007;
ll dis[100005];
bool OK[100005];
vector<P> R[100005];

void DFS(ll a) {
  for (int i = 0; i < R[a].size(); i++) {
    if (!OK[R[a][i].first]) {
      OK[R[a][i].first] = true;
      dis[R[a][i].first] = dis[a] + R[a][i].second;
      DFS(R[a][i].first);
    }
  }
  return ;
}

int main() {
  ll N;
  cin >> N;
  
  for (int i = 0; i < N-1; i++) {
    ll u,v,w;
    cin >> u >> v >> w;
    u--;
    v--;
    R[u].push_back(make_pair(v,w));
    R[v].push_back(make_pair(u,w));
  }
  dis[0] = 0;
  DFS(0);
  for (int i = 0; i < N; i++) {
    cout << dis[i] % 2 << endl;
  }
  return 0;
}