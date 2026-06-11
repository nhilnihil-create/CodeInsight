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
  int n; cin >> n;
  vector<vi> f(n, vi(10));
  for (auto &i : f)
  for (auto &j : i) {
    cin >> j;
  }
  vector<vi> p(n, vi(11));
  for (auto &i : p)
  for (auto &j : i) {
    cin >> j;
  }
  int ans = -2e9;
  for (int i = 1; i < (1 << 10); i++) {
    vector<int> c(n);
    for (int j = 0; j < n; j++)
    for (int k = 0; k < 10; k++) {
      if (f[j][k] && get_bit(i, k)) c[j]++;
    }
    int cal = 0;
    for (int j = 0; j < n; j++) {
      cal += p[j][c[j]];
    }
    ans = max(ans, cal);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
