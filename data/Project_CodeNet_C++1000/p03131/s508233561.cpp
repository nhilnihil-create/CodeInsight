#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll K, A, B;
  cin >> K >> A >> B;

  if (B - A <= 2 || A - 1 >= K) {
    cout << 1 + K << endl;
    return 0;
  }

  ll ans = 1;
  K -= (A - 1);
  ans += A - 1;
  ans += K / 2 * (B - A);
  if (K % 2 == 1) {
    ++ans;
  }

  cout << ans << endl;

  return 0;
}
