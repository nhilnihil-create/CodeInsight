#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 2, vector<int>(m + 2));
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    char c; cin >> c;
    a[i][j] = (c == '#');
  }
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    if (a[i][j] == 1) {
      int cnt = a[i - 1][j] + a[i][j - 1] + a[i + 1][j] + a[i][j + 1];
      if (cnt == 0) {
        cout << "No" << '\n';
        return;
      }
    }
  }
  cout << "Yes" << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}
