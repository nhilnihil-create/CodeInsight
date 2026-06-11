#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;

const int INF = 1001001001;

int main() {
  int N, T, A;
  cin >> N >> T >> A;
  int ans = 0, cc = INF, x;
  repe(i, 1, N) {
    cin >> x;
    int d = abs((T * 1000 - x * 6) - A * 1000);
    if (d < cc) cc = d, ans = i;
  };

  cout << ans << endl;

  return 0;
}
