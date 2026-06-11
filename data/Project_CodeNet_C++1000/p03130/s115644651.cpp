#include <bits/stdc++.h>

using namespace std;

int main() {
  const int n = 4, m = 3;
  vector<int> deg(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    deg[u]++;
    deg[v]++;
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    ok &= (deg[i] == 1 || deg[i] == 2);
  }
  puts(ok ? "YES" : "NO");
  return 0;
}