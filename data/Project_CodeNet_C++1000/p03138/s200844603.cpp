#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using lpair = pair<llong, llong>;

#define ALL(x) x.begin(), x.end()

constexpr llong mod = 1e9+7;
constexpr llong inf = mod * mod;

int main() {
  llong N, K;
  vector<llong> A;

  cin >> N >> K;
  A.resize(N);
  vector<int> many(51, 0);
  for (auto &in: A) {
    cin >> in;
    for (int i = 0; i <= 50; i++) {
      many[i] += (in>>i)&1;
    }
  }

  llong res = 0;
  for (int i = 50; i >= 0; i--) {
    llong cand = 1ll<<i;
    if (res + cand > K) {
      continue;
    }
    if (many[i] < N - many[i]) {
      res += cand;
    }
  }

  llong ans = 0;
  for (auto a: A) {
    ans += res^a;
  }

  cout << ans << endl;

  return 0;
}