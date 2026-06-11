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
  char init[] = {'M', 'A', 'R', 'C', 'H'};
  int n;
  cin >> n;
  vector<long long> cnt(5, 0);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 5; j++) {
      if (s[0] == init[j]) cnt[j]++;
    }
  }
  int cc = 0;
  for (int i = 0; i < 5; i++) {
    if (cnt[i] > 0) cc++;
  }
  if (cc <= 2) {
    cout << 0 << '\n';
    return 0;
  }
  long long ans = 0;
  for (int bit = 0; bit < (1 << 5); bit++) {
    int on_cnt = 0;
    for (int i = 0; i < 5; i++) {
      if (bit & (1 << i)) on_cnt++;
    }
    if (on_cnt != 3) continue;
    long long ans1 = 1;
    for (int i = 0; i < 5; i++) {
      if (bit & (1 << i)) ans1 *= cnt[i];
    }
    ans += ans1;
  }
  cout << ans << '\n';
  return 0;
}