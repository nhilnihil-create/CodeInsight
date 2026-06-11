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
using Graph = vector<vector<int>>;

vector<int> pre, low;
Graph g;
int fst = 0;
int ans = 0;

int dfs(int now, int from) {
  pre[now] = fst;
  low[now] = pre[now];
  fst++;
  for(auto p : g[now]) {
    if(pre[p] == -1) {
      low[now] = min(low[now], dfs(p, now));
      if(low[p] == pre[p]) {
        ans++;
      }
    } else {
      if(p == from) {
        continue;
      }
      low[now] = min(low[now], low[p]);
    }
  }
  return low[now];
}

int main() {
  int n, m;
  cin >> n >> m;
  g.resize(n);
  pre.resize(n);
  low.resize(n);
  for(int i = 0; i < n; i++) {
    pre[i] = -1;
    low[i] = 1001001001;
  }
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, 0);

  cout << ans << endl;
  return 0;
}