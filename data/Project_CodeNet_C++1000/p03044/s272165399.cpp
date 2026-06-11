#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;
int main() {
  ll n;
  cin >> n;
  Graph g(n);
  vector<int> ans(n, -1);
  vector<map<ll, ll>> mp(n);

  for(int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
    mp[u][v] = w;
    mp[v][u] = w;
  }
  ans[0] = 0;
  queue<int> que;
  vector<int> seen(n, 0);
  que.push(0);
  while(!que.empty()) {
    int now = que.front();
    seen[now] = 1;
    que.pop();
    for(auto p : g[now]) {
      if(seen[p] == 1) {
        continue;
      }
      if(mp[now][p] % 2 == 0) {
        ans[p] = ans[now];
      } else {
        ans[p] = ans[now] ? 0 : 1;
      }
      que.push(p);
    }
  }
  for(int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}