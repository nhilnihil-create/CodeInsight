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
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (auto &i : a) cin >> i;
  sort(all(a));
  vector<int> v;
  int s = 0;
  for (int i = 1; i < m; i++) {
    v.push_back(a[i] - a[i - 1]);
    s += v.back();
  }
  sort(all(v), greater<int>());
  for (int i = 0; i < min(n - 1, m - 1); i++) {
    s -= v[i];
  }
  cout << s << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
