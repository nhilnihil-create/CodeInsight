#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using pii = pair<int, int>;
void solve () {
  int n, a, b, ans = 0;
  cin >> n;
  vector<pii> vr(n), vb(n);
  vector<bool> used(n, false);
  rep(i, n) {
    cin >> a >> b;
    vr[i] = make_pair(a, b);
  }
  rep(i, n) {
    cin >> a >> b;
    vb[i] = make_pair(a, b);
  }
  sort(vr.begin(), vr.end(), [](pii p1, pii p2){return p1.second > p2.second;});
  sort(vb.begin(), vb.end());
  rep(i, n) {
    int bx = vb[i].first, by = vb[i].second;
    rep(j, n) {
      if (used[j]) continue;
      int rx = vr[j].first, ry = vr[j].second;
      if (rx >= bx) continue;
      if (ry < by) {
        ++ans;
        used[j] = true;
        break;
      }
    }
  }
  cout << ans << endl;
}
int main () {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}