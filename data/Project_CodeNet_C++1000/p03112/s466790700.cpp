#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, Q;
  cin >> A >> B >> Q;
  vector<long> S(A), T(B);
  for (auto &s : S) cin >> s;
  for (auto &t : T) cin >> t;
  for (long x; cin >> x;) {
    int it = lower_bound(S.begin(), S.end(), x) - S.begin();
    long a = S.at(max(0, it - 1)), b = S.at(min(A - 1, it));
    it = lower_bound(T.begin(), T.end(), x) - T.begin();
    long c = T.at(max(0, it - 1)), d = T.at(min(B - 1, it));
    long ans = 2e18;
    ans = min(ans, abs(x - a) + abs(a - c));
    ans = min(ans, abs(x - a) + abs(a - d));
    ans = min(ans, abs(x - b) + abs(b - c));
    ans = min(ans, abs(x - b) + abs(b - d));
    ans = min(ans, abs(x - c) + abs(c - a));
    ans = min(ans, abs(x - c) + abs(c - b));
    ans = min(ans, abs(x - d) + abs(d - a));
    ans = min(ans, abs(x - d) + abs(d - b));
    cout << ans << "\n";
  }
}