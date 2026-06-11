#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  ll m = (ll)1e15 + 1;
  for (int i = 0; i < 5; i++) {
    ll a;
    cin >> a;
    m = min(m, a);
  }
  cout << 4 + (n + m - 1) / m << '\n';
  return 0;
}
