#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
// ---------------------------------

#define pow abcdef

int pow(int a, int b) {
  if (b == 0) return 1;
  int t = pow(a, b / 2);
  t *= t;
  if (b % 2) return a * t;
  return t;
}

void MAIN() {
  int n; cin >> n;
  vector<int> d(n + 1, 2e9); d[0] = 0;
  for (auto &i : {6, 9}) {
    for (int j = 1; pow(i, j) <= n; j++) {
      int p = pow(i, j);
      for (int k = p; k <= n; k++) {
        d[k] = min(d[k], d[k - p] + 1);
      }
    }
  }
  int ans = 2e9;
  for (int i = 0; i <= n; i++) {
    ans = min(ans, d[i] + n - i);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
