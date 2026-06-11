#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

void MAIN() {
  int n, m;
  cin >> n >> m;
  vector<vector<ii>> a(n + 1);
  for (int i = 1; i <= m; i++) {
    int p, y;
    cin >> p >> y;
    a[p].push_back(ii(y, i));
  }
  vector<string> res(m + 1);
  for (int i = 1; i <= n; i++) {
    sort(all(a[i]));
    for (int j = 0; j < a[i].size(); j++) {
      string sa = to_string(i);
      while (sa.size() < 6) sa = "0" + sa;
      string sb = to_string(j + 1);
      while (sb.size() < 6) sb = "0" + sb;
      res[a[i][j].sc] = sa + sb;
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << res[i] << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
