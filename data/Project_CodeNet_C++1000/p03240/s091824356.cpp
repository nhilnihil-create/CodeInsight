#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
// using Graph = vector<vector<int>>;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

int main() {
  int n;
  cin >> n;
  vector<tuple<int, int, int>> p(n);
  rep(i, n) {
    int x, y, h;
    cin >> x >> y >> h;
    p[i] = make_tuple(x, y, h);
  }
  if (n == 1) {
    cout << get<0>(p[0]) << " " << get<1>(p[0]) << " " << get<2>(p[0]) << endl;
    return 0;
  }
  int f;
  rep(i, 101) rep(j, 101) {
    map<int, int> mp;
    int tmp, cnt = 0;
    rep(k, n) {
      if (get<2>(p[k]) == 0) {
        cnt++;
        continue;
      }
      tmp = abs(i - get<0>(p[k])) + abs(j - get<1>(p[k])) + get<2>(p[k]);
      f = k;
      mp[tmp]++;
    }
    if (mp[tmp] + cnt == n) {
      /* if (mp[tmp] == 1) {
        cout << get<2>(p[f]) << endl;
        return 0;
      } */
      rep(k, n) {
        if (get<2>(p[k]) == 0) {
          if (tmp - abs(i - get<0>(p[k])) - abs(j - get<1>(p[k])) >
              0)
            goto L;
        }
      }
      cout << i << " " << j << " " << tmp << endl;
      return 0;
    }
  L:;
  }
  return 0;
}
