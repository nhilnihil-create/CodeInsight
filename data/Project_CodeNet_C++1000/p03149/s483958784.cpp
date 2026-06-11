#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

const string YES = "YES";
const string NO = "NO";

void solve(vector<ll> N) {
  sort(ALL(N));
  bool pred = accumulate(ALL(N), 0,
                         [](int acc, int x) { return acc * 10 + x; }) == 1479;
  cout << (pred ? YES : NO) << endl;
}

int main() {
  vector<ll> N(4);
  for (int i = 0; i < 4; i++) {
    cin >> N[i];
  }
  solve(move(N));
  return 0;
}
