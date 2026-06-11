#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  cout << (a[1] - a[0]) / 2 + ((a[1] - a[0]) % 2) * 2 + (a[2] - a[1]) << '\n';
  return 0;
}
