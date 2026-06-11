#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; ++i) {
    cin >> A.at(i);
  }
  bool ok = true;
  for (ll i = 0; i < N; ++i) {
    if (i == N - 1) {
      if (A.at(i) > i) {
        ok = false;
      }
      continue;
    }
    if (A.at(i + 1) - 1 <= A.at(i) && A.at(i) <= i) {
      continue;
    }
    ok = false;
    break;
  }
  if (!ok) {
    cout << -1 << "\n";
    return 0;
  }
  ll ans = 0;
  A.push_back(1);
  for (ll i = 0; i < N; ++i) {
    if (A.at(i) >= A.at(i + 1)) {
      ans += A.at(i);
    }
  }
  cout << ans << "\n";
}
