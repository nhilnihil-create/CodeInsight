#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

ll N, A, B, C;

vector<ll> l_list;

ll calc(ll bits[]) {
  ll a = 0;
  ll b = 0;
  ll c = 0;

  ll r = 0;

  for (ll i = N - 1; i >= 0; i--) {
    // cout << bits[i];

    switch (bits[i]) {
      case 1:
        if (a > 0) {
          r += 10;
        }
        a += l_list[i];
        break;
      case 2:
        if (b > 0) {
          r += 10;
        }
        b += l_list[i];
        break;
      case 3:
        if (c > 0) {
          r += 10;
        }
        c += l_list[i];
        break;
    }
  }

  if (a == 0 || b == 0 || c == 0) {
    return INF;
  }

  r += abs(A - a);
  r += abs(B - b);
  r += abs(C - c);
  return r;
}

int main() {
  scanf("%lld %lld %lld %lld", &N, &A, &B, &C);

  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    l_list.emplace_back(v);
  }

  ll base = 4;
  ll K = N;
  ll bits[K];
  fill_n(bits, K, 0);

  ll ans = INF;

  for (;;) {
    bool finish = false;

    ll v = calc(bits);
    if (v < ans) {
      ans = v;

      // for (ll i = K - 1; i >= 0; i--) {
      //   cout << bits[i];
      // }
      // cout << endl;
      // cout << v << endl;
    }

    for (ll i = 0; i < K; i++) {
      if (bits[i] + 1 < base) {
        bits[i] += 1;
        break;
      } else {
        bits[i] = 0;

        if (i == K - 1) {
          finish = true;
          break;
        }
      }
    }
    if (finish) {
      break;
    }
  }

  cout << ans << endl;
}
