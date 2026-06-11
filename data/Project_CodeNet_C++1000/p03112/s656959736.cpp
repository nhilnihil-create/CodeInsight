#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(20) << fixed;

  long long a, b, q;
  cin >> a >> b >> q;

  vector<long long> s(a), t(b);
  for (int i = 0; i < a; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < b; i++) {
    cin >> t[i];
  }

  while (q--) {
    long long x; cin >> x;
    long long ans = 2e10+10;

    int sr = lower_bound(s.begin(), s.end(), x) - s.begin();
    int sl = sr-1;

    int tr = lower_bound(t.begin(), t.end(), x) - t.begin();
    int tl = tr-1;

    // 右に神社, 右に寺
    if (sr < a && tr < b) {
      long long rd1 = abs(s[sr] - x);
      long long rd2 = abs(t[tr] - x);
      ans = min(ans, max(rd1, rd2));
    }
    // 左に神社, 左に寺
    if (sl >= 0 && tl >= 0) {
      long long ld1 = abs(s[sl] - x);
      long long ld2 = abs(t[tl] - x);
      ans = min(ans, max(ld1, ld2));
    }
    // 右に神社, 左に寺
    if (sr < a && tl >= 0) {
      long long rd = abs(s[sr] - x);
      long long ld = abs(t[tl] - x);
      ans = min(ans, rd+ld+min(rd, ld));
    }
    // 左に神社, 右に寺
    if (sl >= 0 && tr < b) {
      long long rd = abs(t[tr] - x);
      long long ld = abs(s[sl] - x);
      ans = min(ans, rd+ld+min(rd, ld));
    }

    cout << ans << endl;
  }

  return 0;
}
