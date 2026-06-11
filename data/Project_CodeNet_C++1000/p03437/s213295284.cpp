#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  ll X, Y;
  cin >> X >> Y;
  if (X % Y == 0) {
    cout << -1 << endl;
    return 0;
  }
  ll ans = X;
  while (true) {
    if (ans % Y != 0) {
      cout << ans << endl;
      return 0;
    }
    ans += X;
  }
}