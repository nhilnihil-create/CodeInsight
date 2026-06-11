#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

std::vector<bool> IsPrime;

void sieve(size_t max) {
  if (max + 1 > IsPrime.size()) {
    IsPrime.resize(max + 1, true);
  }
  IsPrime[0] = false;
  IsPrime[1] = false;

  for (size_t i = 2; i * i <= max; ++i) {
    if (IsPrime[i]) {
      for (size_t j = 2; i * j <= max; ++j) {
        IsPrime[i * j] = false;
      }
    }
  }
}

int main() {
  sieve(100005);

  ll Q;
  scanf("%lld", &Q);

  vll a = vll(100005);

  for (ll i = 1; i <= 100000; i++) {
    if (IsPrime[i] && IsPrime[(i + 1) / 2]) {
      a[i] = 1;
    } else {
      a[i] = 0;
    }
  }

  vector<ll> csum(100005);
  for (ll i = 1; i < a.size() + 1; i++) {
    csum[i] = csum[i - 1] + a[i - 1];
  }

  // // [2] + [3] + [4]
  // cout << (csum[4 + 1] - csum[2]) << endl;
  // // [1] + [2] + [3]
  // cout << (csum[3 + 1] - csum[1]) << endl;

  for (ll i = 0; i < Q; i++) {
    ll l, r;
    scanf("%lld %lld", &l, &r);

    // // [2] + [3] + [4]
    cout << (csum[r + 1] - csum[l]) << endl;
  }
}
