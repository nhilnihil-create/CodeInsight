#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)

vector<pair<ll,ll>> E[100005];
ll ans[100005];

void dfs(ll fro, ll to, ll dis) {
  ans[to] = dis%2;
  for (auto& e:E[to]) {
    if (e.first != fro) dfs(to, e.first, dis+e.second);
  }
}

int main() {
  int n;
  cin >> n;
  ll u,v,w;
  rep(i,n-1) {
    cin >> u >> v >> w;
    E[u-1].push_back({v-1, w%2});
    E[v-1].push_back({u-1, w%2});
  }
  dfs(-1,0,0);
  rep(i,n) printf("%lld\n", ans[i]);
  return 0;
}
