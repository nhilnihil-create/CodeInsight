#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define popcnt __builtin_popcount
#define getBit(x, k) ((x >> k) & 1)
#define all(x) (x).begin(),(x).end()
// ---------------------------------

void Main() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      c += a[i] - b[i];
      b[i] = a[i];
    }
  }
  for (int i = 0; i < n; i++) {
    c -= min(c, max(0ll, (b[i] - a[i]) / 2));
  }
  if (c) cout << "No" << '\n';
  else cout << "Yes" << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  cerr << "- ---- -- ----- <3\n";
#endif
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  // cin >> T;
  while (T--) Main();
}
