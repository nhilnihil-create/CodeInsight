#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll N, ll M, ll X, vector<ll> A) {
  sort(ALL(A));
  ll d = lower_bound(ALL(A),X) - A.begin();
  cout << min(d,M-d) << endl;
}

int main() {
  ll N;
  cin >> N;
  ll M;
  cin >> M;
  ll X;
  cin >> X;
  vector<ll> A(M);
  for (int i = 0; i < M; i++) {
    cin >> A[i];
  }
  solve(N, M, X, move(A));
  return 0;
}
