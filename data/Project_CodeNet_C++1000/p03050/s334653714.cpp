#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

// 約数の列挙O(√n)
vector<ll> divisor(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i) res.push_back(n / i);
    }
  }
  return res;
}

int main() {
  ll N;
  cin >> N;
  auto divs = divisor(N);
  ll ans = 0;
  for (int i = 0; i < divs.size(); i++) {
    ll x = N / divs[i] - 1;
    if (x != 0 && N / x == N % x) ans += x;
  }
  cout << ans << endl;
  return 0;
}