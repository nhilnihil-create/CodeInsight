#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(vector<ll> A) {
  cout << *max_element(ALL(A)) - *min_element(ALL(A)) << endl;
}

int main() {
  vector<ll> A(3);
  for (int i = 0; i < 3; i++) {
    cin >> A[i];
  }
  solve(move(A));
  return 0;
}
