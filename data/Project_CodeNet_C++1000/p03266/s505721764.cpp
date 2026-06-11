#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  ll N, K;
  cin >> N >> K;
  ll d = N / K;
  ll ans = d * d * d;

  if (K % 2 != 0) {
    cout << ans << endl;
    return 0;
  }

  ll dd = 0;
  if (N - (K / 2) >= 0) {
    dd = (N - (K / 2)) / K + 1;
  }
  ans += dd * dd * dd;
  cout << ans << endl;
}
