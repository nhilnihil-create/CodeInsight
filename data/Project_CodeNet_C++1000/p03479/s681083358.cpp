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
  int a, b;
  cin >> a >> b;
  int ans = 0;
  while (a <= b) ans++, a *= 2;
  cout << ans << '\n';
  return 0;
}
