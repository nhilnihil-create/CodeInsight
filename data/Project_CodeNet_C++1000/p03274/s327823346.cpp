#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long

void solve(void) {
  ll N, K;
  cin >> N >> K;

  vector<ll> candle(N);
  for (ll i = 0; i < N; ++i) cin >> candle[i];

  ll res = 10000000000;

  for (ll ci = 0; ci + (K-1) < N; ++ci) {
    ll left = candle[ci];
    ll right = candle[ci+(K-1)];

    ll dist1 = abs(left) + abs(right - left);
    ll dist2 = abs(right) + abs(right - left);

    res = min(res, min(dist1, dist2));
  }
  cout << res << endl;
}

int main(void) {
  solve();
  return 0;
}