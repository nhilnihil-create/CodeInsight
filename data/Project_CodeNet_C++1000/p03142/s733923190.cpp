#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;

vector<int> g[100 * 1000 + 218];
int ans[100 * 1000 + 218];
int to[100 * 1000 + 218];

int GetMaxPath(int v) {
  if (g[v].empty()) return 0;
  if (ans[v] != -1) return ans[v];
  ans[v] = 0;
  for (int t = 0; t < g[v].size(); ++t) {
    if (ans[v] < 1 + GetMaxPath(g[v][t])) {
      ans[v] = 1 + GetMaxPath(g[v][t]);
      to[v] = g[v][t];
    }
  }
  return ans[v];
}


int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n - 1 + m; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[b].push_back(a);
  }

  memset(ans, -1, sizeof(ans));
  for (int i = 0; i < n; ++i) GetMaxPath(i);

  for (int i = 0; i < n; ++i) {
    if (g[i].empty()) {
      cout << 0 << endl;
      continue;
    }
    cout << to[i] + 1 << endl;
  }

  return 0;
}
