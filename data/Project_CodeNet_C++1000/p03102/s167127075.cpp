#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n, m, c;
   cin >> n >> m >> c;
   vector<int> b(m);
   for (int i = 0; i < m; i++) {
      cin >> b[i];
   }
   int ans = 0;
   vector<vector<int>> a(n, vector<int>(m));
   for (int i = 0; i < n; i++) {
      long long e = c;
      for (int j = 0; j < m; j++) {
         cin >> a[i][j];
         e += a[i][j] * b[j];
      }
      if (e > 0) ans++;
   }
   cout << ans << '\n';
   return 0;
}