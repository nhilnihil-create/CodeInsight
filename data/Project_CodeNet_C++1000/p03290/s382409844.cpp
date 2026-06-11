#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

int point(int x) {
  return x * 100;
}

int ceil_div(int a, int b) {
  return (a + b - 1) / b;
}

void MAIN() {
  int n, g;
  cin >> n >> g;
  vector<int> a(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> c[i];
  }
  int ans = 2e9;
  for (int i = 0; i < (1 << n); i++) {
    int cnt = 0, pnt = 0;
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        cnt += a[j];
        pnt += a[j] * point(j + 1) + c[j];
      }
    }
    for (int j = n - 1; j >= 0; j--) {
      if (pnt >= g) break;
      if (((i >> j) & 1) == 0) {
        int t = ceil_div(g - pnt, point(j + 1));
        t = min(t, a[j]);
        cnt += t;
        pnt += t * point(j + 1);
      }
    }
    ans = min(ans, cnt);
  }
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
