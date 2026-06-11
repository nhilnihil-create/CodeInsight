#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

int cnt(int n) {
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) ret++;
  }
  return ret;
}

void solve() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 2 && cnt(i) == 8) {
      ans++;
    }
  }
  cout << ans << '\n';
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
