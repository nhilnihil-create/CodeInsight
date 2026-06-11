#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

vector<int> g[10000];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  sort(c.begin(), c.end());
  int sum = 0;
  for (int i = 0; i < n - 1; ++i) {
    sum += c[i];
  }
  vector<int> ans(n, -1);
  queue<int> que;
  que.push(0);
  ans[0] = c.back();
  c.pop_back();
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (auto u : g[v]) {
      if (ans[u] == -1) {
        que.push(u);
        ans[u] = c.back();
        c.pop_back();
      }
    }
  }
  cout << sum << endl;
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }
  return 0;
}