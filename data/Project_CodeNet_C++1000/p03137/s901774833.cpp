#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  if (n >= m) {
    cout << 0 << endl;
    return 0;
  }
  vector<int> x(m), dist(m - 1), csum(m + 1);
  rep(i, m) cin >> x[i];
  sort(x.begin(), x.end());
  rep(i, m - 1) dist[i] = x[i + 1] - x[i];
  sort(dist.rbegin(), dist.rend());
  int ans = x[m - 1] - x[0];
  rep(i, n - 1) ans -= dist[i];
  cout << ans << endl;
  return 0;
}
