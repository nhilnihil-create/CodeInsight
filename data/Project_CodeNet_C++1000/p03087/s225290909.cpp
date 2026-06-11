#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> a(n);
  for (int i = 1; i < n; i++) {
    a[i] = a[i - 1];
    if (s.substr(i - 1, 2) == "AC") a[i]++;
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    cout << a[r] - a[l] << '\n';
  }
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
