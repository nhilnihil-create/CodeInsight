#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

void MAIN() {
  int n, m;
  cin >> n >> m;
  vector<ii> a(n);
  set<int> r, c;
  for (auto &i : a) {
    cin >> i.fi >> i.sc;
    r.insert(i.fi);
    c.insert(i.sc);
  }
  int ans = LLONG_MAX;
  for (auto &x1 : r)
  for (auto &y1 : c) 
  for (auto &x2 : r)
  for (auto &y2 : c) {
    if (x2 < x1 || y2 < y1) continue;
    int cnt = 0;
    for (auto &i : a) {
      if (x1 <= i.fi && i.fi <= x2 && y1 <= i.sc && i.sc <= y2) {
        cnt++;
      }
    }
    if (cnt >= m) {
      ans = min(ans, (x2 - x1) * (y2 - y1));
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
