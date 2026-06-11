#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;

using pint = pair<int, int>;

int main() {
  int N, M, X;
  cin >> N >> M >> X;
  int tot_0 = 0, tot_n = 0, a;
  rep(i, 0, M) {
    cin >> a;
    if (a < X) {
      tot_0++;
    } else if (a > X) {
      tot_n++;
    }
  };

  cout << min(tot_0, tot_n) << endl;

  return 0;
}
