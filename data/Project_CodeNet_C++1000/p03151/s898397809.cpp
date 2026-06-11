#include <algorithm>
#include <iostream>
#include <vector>

#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void()
#endif

int main() {
  using namespace std;
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int ans = 0;
  long long req = 0;
  vector<int> suf;
  for (int i = 0; i < n; i++) {
    if (a[i] - b[i] < 0) {
      ans++;
      req += b[i] - a[i];
    } else if (a[i] - b[i] > 0) {
      suf.emplace_back(a[i] - b[i]);
    }
  }
  debug(req, ans);
  sort(suf.begin(), suf.end(), greater<int>());
  long long suf_sum = 0;
  for (int i = 0; i < (int)suf.size(); i++) {
    if (suf_sum >= req) break;
    suf_sum += suf[i];
    ans++;
  }
  if (suf_sum >= req) {
    cout << ans << '\n';
  } else {
    cout << -1 << '\n';
  }
  return 0;
}