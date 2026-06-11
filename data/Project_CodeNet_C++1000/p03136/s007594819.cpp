#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

const string YES = "Yes";
const string NO = "No";

void solve(ll N, vector<ll> L) {
  ll ma = *max_element(ALL(L));
  bool pred = accumulate(ALL(L),0ll) > 2*ma;
  cout << (pred ? YES : NO) << endl;
}

int main() {
  ll N;
  cin >> N;
  vector<ll> L(N);
  for (int i = 0; i < N; i++) {
    cin >> L[i];
  }
  solve(N, move(L));
  return 0;
}
