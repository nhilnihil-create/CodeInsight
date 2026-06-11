#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (a % b == 0) return b;
  return gcd(a % b, b);
}

int main(void) {
  ll N, X;
  cin >> N >> X;
  vector<ll> x(N);
  rep(i, N) {
    cin >> x[i];
  }

  if (N == 1) {
    cout << abs(X - x[0]) << endl;
    return 0;
  }


  ll D = gcd(abs(X - x[0]), abs(X - x[1]));
  for (int i = 2; i < N; ++i) {
    D = gcd(D, (ll)abs(X - x[i]));
  }

  cout << D << endl;

  return 0;
}