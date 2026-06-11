#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];

  ll s = accumulate(a.begin(), a.end(), 0ll);
  ll t = accumulate(b.begin(), b.end(), 0ll);
  if (s < t)
    cout << "-1" << endl;
  else {
    vector<ll> enough;
    ll need = 0;
    ll ans = 0;
    rep(i, 0, n) {
      if (a[i] < b[i]) {
        need += b[i] - a[i];
        ans++;
      } else
        enough.push_back(a[i] - b[i]);
    }
    sort(enough.rbegin(), enough.rend());
    rep(i, 0, enough.size()) {
      if (need <= 0) break;
      need -= enough[i];
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}