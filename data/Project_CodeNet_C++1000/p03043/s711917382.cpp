#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define l_l pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

ll N, K;

ll getNum(ll n) {
  ll r = 0;
  for (;;) {
    if (n >= K) {
      break;
    }
    n *= 2;
    r++;
  }
  return r;
}

int main() {
  std::cout << std::fixed << std::setprecision(10);
  scanf("%lld %lld", &N, &K);

  double ans = 0;
  for (ll i = 1; i <= N; i++) {
    ll n = getNum(i);
    double plus = powf(0.5, n);
    ans += plus;
  }

  cout << ans / N << endl;

  // cout << (log2(5)) << endl;
}
