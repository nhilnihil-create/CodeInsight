#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, T;
  cin >> N >> T;
  int res = 1 << 28;
  for (int i = 0; i < N; i++) {
    int c, t;
    cin >> c >> t;
    if (t > T) continue;
    res = min(res, c);
  }
  if (res == (1 << 28)) {
    cout << "TLE" << '\n';
  } else {
    cout << res << '\n';
  }
  return 0;
}
