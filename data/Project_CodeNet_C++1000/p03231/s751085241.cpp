#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void()
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  long long ans = lcm(n, m);
  map<long long, char> mp;
  for (int i = 0; i < n; i++) {
    mp[1 + ans / n * i] = s[i];
  }
  bool ok = true;
  for (int i = 0; i < m; i++) {
    if (mp.count(1 + ans / m * i)) {
      if (mp[1 + ans / m * i] != t[i]) {
        ok = false;
        break;
      }
    }
  }
  if (ok) {
    cout << ans << '\n';
  } else {
    cout << -1 << '\n';
  }
  return 0;
}