#include <bits/stdc++.h>
using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int n, m; cin >> n >> m;
   string s; cin >> s;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) a[i] = s[i] - 'A';
   vector<vector<int>> g(n);
   vector<vector<int>> deg(n, vector<int>(2, 0));
   for (int i = 0; i < m; ++i) {
      int u, v; cin >> u >> v; u--, v--;
      deg[u][a[v]]++;
      deg[v][a[u]]++;
      g[u].push_back(v);
      g[v].push_back(u);
   }
   vector<int> was(n, 0);
   vector<int> q;
   for (int i = 0; i < n; ++i) {
      if (deg[i][0] == 0 || deg[i][1] == 0) {
         was[i] = 1;
         q.push_back(i);
      }
   }
   for (int i = 0; i < q.size(); ++i) {
      int u = q[i];
      for (int v : g[u]) {
         deg[v][a[u]]--;
         if (deg[v][0] == 0 || deg[v][1] == 0) {
            if (was[v] == 0) {
               was[v] = 1;
               q.push_back(v);
            }
         }
      }
   }
   cout << (q.size() == n ? "No" : "Yes") << '\n';
}
