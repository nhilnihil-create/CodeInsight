#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int INF = 1001001001;

int main() {
  int N, T;
  cin >> N >> T;
  int ans = INF;
  rep(i, 0, N) {
    int c, t;
    cin >> c >> t;
    if (t > T) continue;
    ans = min(ans, c);
  }

  if (ans == INF)
    cout << "TLE" << endl;
  else
    cout << ans << endl;

  return 0;
}
