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
  n--;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  for (int i = 0; i < n; i++) {
    int t = 0, ans = 0;
    for (int j = i; j < n; j++) {
      if (t >= b[j]) {
        int d = ((t - 1) / c[j] + 1) * c[j];
        ans += d - t;
        t = d;
      }
      else {
        ans += b[j] - t;
        t = b[j];
      }
      ans += a[j];
      t += a[j];
    }
    cout << ans << '\n';
  }
  cout << 0 << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
