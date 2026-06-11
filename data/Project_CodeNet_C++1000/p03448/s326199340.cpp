#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A, B, C, X;
  cin >> A >> B >> C >> X;

  int ans = 0;
  REP(a, A + 1) {
    REP(b, B + 1) {
      int sum = a * 500 + b * 100;
      if (sum > X) {
        break;
      }
      if (sum == X) {
        ++ans;
        break;
      }

      REP(c, C + 1) {
        if (sum + c * 50 == X) {
          ++ans;
          break;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
