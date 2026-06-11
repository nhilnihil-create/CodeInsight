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
  string s; cin >> s;
  int r = 0, b = 0;
  for (auto i : s) if (i == '0') r++; else b++;
  cout << min(r, b) * 2 << '\n';
  return 0;
}
