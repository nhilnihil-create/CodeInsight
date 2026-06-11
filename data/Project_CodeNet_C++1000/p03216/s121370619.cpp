#include <algorithm>
#include <iostream>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

int main() {
  int n, q, k;
  string s;
  cin >> n >> s >> q;
  while (q--) {
    cin >> k;
    ll D = 0, M = 0, DM = 0, ans = 0;
    rep(i, 0, n) {
      if (s[i] == 'D')
        ++D;
      else if (s[i] == 'M')
        DM += D, ++M;
      else if (s[i] == 'C')
        ans += DM;
      if (i - k + 1 >= 0) {
        if (s[i - k + 1] == 'D') {
          --D;
          DM -= M;
        } else if (s[i - k + 1] == 'M')
          --M;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}