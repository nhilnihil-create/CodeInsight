#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set

using namespace std;

const ll MOD = 1000000007;
const ll INF = (1LL << 62);

int main() {
  ll a, b;
  scanf("%lld %lld", &a, &b);

  ll v;
  if (a % 2 == 0 && b % 2 == 0) {
    ll pair_num = (b - a) / 2;
    v = b ^ ((pair_num % 2 == 0) ? 0 : 1);
  } else if (a % 2 == 1 && b % 2 == 0) {
    ll pair_num = (b - a) / 2;
    v = a ^ b ^ ((pair_num % 2 == 0) ? 0 : 1);
  } else if (a % 2 == 0 && b % 2 == 1) {
    ll pair_num = (b - a + 1) / 2;
    v = ((pair_num % 2 == 0) ? 0 : 1);
  } else if (a % 2 == 1 && b % 2 == 1) {
    ll pair_num = (b - a) / 2;
    v = a ^ ((pair_num % 2 == 0) ? 0 : 1);
  }

  cout << v << endl;

  // ll v2 = a;
  // for (ll i = a + 1; i <= b; i++) {
  //   v2 = v2 ^ i;
  // }
  // cout << v2 << endl;
}
