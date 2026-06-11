#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int N;
  cin >> N;
  ll ans = 0;

  vector<ll> v(N + 1, 0);
  v[0] = 2;
  v[1] = 1;
  rep(i, 2, N + 1) v[i] = v[i - 2] + v[i - 1];

  cout << v[N] << endl;

  return 0;
}
