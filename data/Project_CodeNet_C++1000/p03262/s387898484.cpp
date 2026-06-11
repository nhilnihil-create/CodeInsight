#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
// ---------------------------------

void MAIN() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int t = abs(x - a[0]);
  for (int i = 1; i < n; i++) {
    t = __gcd(t, abs(x - a[i]));
  }
  cout << t << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
