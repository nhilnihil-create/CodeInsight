#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 1; i <= N; i += 2) {
    int cnt = 0;
    repe(j, 1, i) if (i % j == 0) cnt++;
    if (cnt == 8) ans++;
  }

  cout << ans << endl;

  return 0;
}
