#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int h, w, n;
  cin >> h >> w >> n;
  vvi y(w, vi(1, h));
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    y[b].push_back(a);
  }
  for (int i = 0; i < w; ++i) {
    sort(y[i].begin(), y[i].end());
    y[i].resize(unique(y[i].begin(), y[i].end()) - y[i].begin());
  }
  int res = h, pos = 0, cur = 0;
  for (int i = 0; i < w && pos < h; ++i) {
    int it = lower_bound(y[i].begin(), y[i].end(), pos) - y[i].begin();
    res = min(res, cur + (y[i][it] - pos));
    ++pos;
    ++cur;
    if (i + 1 < w) while (pos < h && binary_search(y[i+1].begin(), y[i+1].end(), pos)) {
      ++pos;
      ++cur;
    }
  }
  cout << res << endl;
  return 0;
}