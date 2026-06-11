
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int reverse_game(ll i, const vector<ll>& as, ll& n_min, ll& n_max) {
  i--;
  if (n_max < as[i])
    return -1;
  if (i == 0) {
    n_max += as[0] - 1;
    return 0;
  }
  auto d_min = (n_min - 1)/as[i - 1];
  n_max += as[i] - 1;
  auto d_max = n_max/as[i - 1];
  if (d_min==d_max)
    return -1;
  n_min = (d_min + 1)*as[i - 1];
  n_max = d_max*as[i - 1];
  return reverse_game(i, as, n_min, n_max);
}

int main() {
  ll k;
  cin >> k;
  if (k < 1 || pow(10, 5) < k) {
    cout << "-1";
    return 0;
  }
  vector<ll> a(k);
  for (auto & z : a) {
    cin >> z;
  }
  for (auto & z : a) {
    if (z < 2 || pow(10, 9) < z ) {
      cout << "-1";
      return 0;
    }
  }

  ll n_min=2, n_max=2;
  if(reverse_game(k, a, n_min, n_max) == 0) {
    cout << n_min << " " << n_max;
  } else {
    cout << "-1";
  }
  return 0;
}
