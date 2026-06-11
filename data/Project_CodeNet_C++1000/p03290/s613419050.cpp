#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define int long long int
constexpr int INF = std::numeric_limits<int>::max();
constexpr int NINF = std::numeric_limits<int>::min();
using namespace std;

void solve() {
  int D, G;
  vector<int> vp, vc;

  cin >> D >> G;

  int ans = INF;

  for (int i = 0; i < D; i++) {
    int p, c; cin >> p >> c;
    vp.push_back(p);
    vc.push_back(c);
  }

  for (int bit = 0; bit < (1<<D); bit++) {
    int tmpsum = 0;
    int cnt = 0;
    for (int i = 0; i < D; i++) {
      if (bit & (1<<i)) {
        tmpsum += vc[i] + vp[i]*(i+1)*100;
        cnt += vp[i];
      }
    }

    for (int i = D-1; i >= 0; i--) {
      if (tmpsum >= G) {
        break;
      }
      if (!(bit & (1<<i))) {
        int point = (i+1)*100;
        int c = min((G-tmpsum+point-1)/point, vp[i]-1);
        cnt += c;
        tmpsum += c * point;
      }
    }
    if (tmpsum >= G) {
      ans = min(ans, cnt);
    }
  }
  cout << ans << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
