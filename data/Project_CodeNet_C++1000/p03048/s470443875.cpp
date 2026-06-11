#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll R, G, B, N;
  cin >> R >> G >> B >> N;

  int ans = 0;
  REP(r, 3001) {
    REP(g, 3001) {
      ll n = N - (R * r + G * g);
      if (n < 0) {
        continue;
      }

      if (n == 0 || n % B == 0) {
        ++ans;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
