#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  bool flag = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') {
      flag = 1;
    }
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  if (flag) {
    x = -x;
  }
}
const int N = 200005;
int n, f[N], r;
vector<int> g[N];
void dfs(int u, int fa) {
  for (auto v : g[u]) {
    if (v ^ fa) {
      dfs(v, u);
      r = max(r, f[u] + f[v] + 2);
      f[u] = max(f[u], f[v] + 1);
    }
  }
}
int main() {
  read(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u), read(v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  puts((r - 2) % 3 ? "First" : "Second");
  return 0;
}