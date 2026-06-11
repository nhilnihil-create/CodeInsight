#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  ios_base::sync_with_stdio(false);

  int N;
  llint X;
  cin >> N >> X;

  vector<llint> x(N);
  REP(i, N) cin >> x[i];

  vector<llint> p(N + 1);
  p[0] = 0;
  REP(i, N) p[i + 1] = p[i] + x[i];

  llint ret = 1e18;
  for (int K = 1; K <= N; ++K) {
    llint cost = (N + K) * X;

    int i = N, it = 0;
    while (i > 0 && cost < ret) {
      int it_cost = it == 0 ? 5 : 3 + 2 * it;
      int ni = max(0, i - K);
      cost += (p[i] - p[ni]) * it_cost;
      i = ni;
      it++;
    }

    ret = min(ret, cost);
  }

  cout << ret << "\n";
  return 0;
}
