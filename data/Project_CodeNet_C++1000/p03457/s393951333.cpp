#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

int dis(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

void solve() {
  int n;
  cin >> n;
  vector<int> t(n + 1), x(n + 1), y(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> x[i] >> y[i];
    int dt = t[i] - t[i - 1];
    int dd = dis(x[i], y[i], x[i - 1], y[i - 1]);
    if (!(dt >= dd && (dt - dd) % 2 == 0)) {
      cout << "No" << '\n';
      return;
    }
  }
  cout << "Yes" << '\n';
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
