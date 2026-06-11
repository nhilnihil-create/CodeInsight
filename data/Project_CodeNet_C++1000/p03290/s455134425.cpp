#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  int D, G;
  cin >> D >> G;
  vector<int> p(D);
  vector<int> c(D);
  rep(i, D) {
    cin >> p[i] >> c[i];
  }

  ll ans = 1<<29;
  for (int bit = 0; bit < (1<<D); ++bit) {
    ll sum = 0;
    ll count = 0;
    rep(i, D) {
      if (bit & (1<<i)) {
        sum += c[i] + p[i] * 100 * (i+1);
        count += p[i];
      }
    }
    if (sum >= G) ans = min(ans, count);
    else {
      for (int i = D - 1; i >= 0; --i) {
        if (bit & (1<<i)) continue;
        for (int j = 0; j < p[i]; ++j) {
          if (sum >= G) break;
          sum += 100 * (i+1);
          ++count;
        }
      }
      ans = min(ans, count);
    }
  }

  cout << ans << endl;
  
  return 0;
}