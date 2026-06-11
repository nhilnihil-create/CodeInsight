#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll N, vector<ll> p) {
  cout << accumulate(ALL(p),0ll) - *max_element(ALL(p))/2 << endl;
}

int main() {
  ll N;
  cin >> N;
  vector<ll> p(N);
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }
  solve(N, move(p));
  return 0;
}
