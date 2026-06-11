#include <bits/stdc++.h>
using namespace std;

// ----------- define ---------------
#define int long long
#define vi vector<int>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define popcnt __builtin_popcount
#define getbit(x, k) ((x >> k) & 1)
#define all(x) (x).begin(), (x).end()
// ----------------------------------

void MAIN() {
  int n, h;
  cin >> n >> h;
  vector<ii> a(n);
  int ma = 0;
  for (auto &i : a) {
    cin >> i.fi >> i.sc;
    ma = max(ma, i.fi);
  }
  sort(all(a), [](ii &a, ii &b) -> bool {
    return a.sc > b.sc;
  });
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].sc > ma) {
      ans++;
      h -= a[i].sc;
      if (h <= 0) {
        cout << ans << '\n';
        return;
      }
    }
    else break;
  }
  sort(all(a), greater<ii>());
  /*while (h > 0) {
    h -= a[0].fi;
    ans++;
  }*/
  ans += (h + a[0].fi - 1) / a[0].fi;
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
