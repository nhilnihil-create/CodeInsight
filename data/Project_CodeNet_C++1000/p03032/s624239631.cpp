#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;
  int v[n];
  rep(i, n) cin >> v[i];

  int ans = 0;

  for (int a = 0; a <= min(n, k); ++a) {
    vector<int> g;
    rep(i, a) g.push_back(v[i]);

    for (int b = 0; b <= min(n, k) - a; ++b) {
      vector<int> h;
      copy(g.begin(), g.end(), back_inserter(h));
      rep(i, b) h.push_back(v[n - i - 1]);
      sort(h.begin(), h.end());

      int res = k - (a + b);
      int cur = 0;
      int m = h.size();
      rep(i, min(res, m)) if (h[i] < 0)++ cur;
      int sum = 0;
      while (cur < m) sum += h[cur++];
      ans = max(ans, sum);
    }
  }
  cout << ans << endl;
  return 0;
}
