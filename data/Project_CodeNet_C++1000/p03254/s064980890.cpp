#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(all(a));
  for (int i = 0; i < n; i++) {
    x -= a[i];
    if (x < 0 || (i == n - 1 && x != 0)) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << n << '\n';
}
