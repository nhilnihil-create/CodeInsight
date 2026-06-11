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
  vector<int> a(n), l(n), r(n);
  for (auto &i : a) cin >> i;
  for (int i = 0; i < n; i++) {
    l[i] = a[i];
    if (i) l[i] = __gcd(l[i], l[i - 1]);
  }
  for (int i = n - 1; i >= 0; i--) {
    r[i] = a[i];
    if (i != n - 1) r[i] = __gcd(r[i], r[i + 1]);
  }
  int ans = max(r[1], l[n - 2]);
  for (int i = 1; i < n - 1; i++) {
    ans = max(ans, __gcd(l[i - 1], r[i + 1]));
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
