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

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  ll A, B;
  scanf("%lld %lld", &A, &B);

  ll val;

  ll start_even = (A % 2 == 0) ? A : A + 1;
  ll end_odd = (B % 2 == 1) ? B : B - 1;

  ll pair_count = (end_odd - start_even + 1) / 2;

  ll v = (pair_count % 2 == 1) ? 1 : 0;

  if (A % 2 == 1) {
    v ^= A;
  }
  if (B % 2 == 0) {
    v ^= B;
  }
  cout << v << endl;
}
