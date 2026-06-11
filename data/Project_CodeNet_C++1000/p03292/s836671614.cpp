#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A1, A2, A3;
  cin >> A1 >> A2 >> A3;

  int ans = 1000;
  ans = min(ans, abs(A2 - A1) + abs(A3 - A2));
  ans = min(ans, abs(A3 - A2) + abs(A1 - A3));
  ans = min(ans, abs(A1 - A3) + abs(A2 - A1));

  cout << ans << endl;

  return 0;
}
