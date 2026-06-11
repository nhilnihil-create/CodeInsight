#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n), h(n);
  rep(i, n) cin >> x[i] >> y[i] >> h[i];

  rep(cx, 101) rep(cy, 101) {
    vector<tuple<ll, ll, ll>> cand;
    rep(i, n) {
      if (h[i] <= 0) continue;
      ll H = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
      cand.emplace_back(cx, cy, H);
    }

    rep(i, cand.size()) {
      bool flag = true;
      ll cx = get<0>(cand[i]), cy = get<1>(cand[i]), H = get<2>(cand[i]);
      rep(j, n) {
        ll hh = max(H - abs(x[j] - cx) - abs(y[j] - cy), 0LL);
        flag &= (hh == h[j]);
      }
      if (flag) {
        cout << cx << " " << cy << " " << H << endl;
        return 0;
      }
    }
  }
  return 0;
}
