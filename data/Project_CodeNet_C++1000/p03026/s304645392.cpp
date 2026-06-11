#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
 
using ll = long long;
using ld = long double;
const int root = 0;
 
int main() {
  int n;
  cin >> n;
  vector<vector<int>> inp(n);
  for (int i = 0, a, b; i + 1 < n; ++i) {
    cin >> a >> b;
    inp[a - 1].push_back(b - 1);
    inp[b - 1].push_back(a - 1);
  }
 
  vector<int> c(n);
  for (auto &c_i : c) cin >> c_i;
  sort(c.begin(), c.end(), greater<int>());
 
  int max_sum = 0, idx = 0;
  vector<int> max_w(n, -1);
  queue<int> que;
  que.push(root);
  max_w[root] = c[idx++];
 
  while (!que.empty()) {
    int cur = que.front(); que.pop();
    for (auto u : inp[cur]) {
      if (max_w[u] != -1) continue;
      max_w[u] = c[idx++];
      max_sum += min(max_w[cur], max_w[u]);
      que.push(u);
    }
  }
 
  cout << max_sum << endl;
  for (int v = 0; v < n; ++v) {
    cout << max_w[v] << " \n"[v == n - 1];
  }
  return 0;
}