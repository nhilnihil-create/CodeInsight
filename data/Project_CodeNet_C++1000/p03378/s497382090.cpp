#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M, X;
  cin >> N >> M >> X;
  vector<int> A(N);
  REP(i, N) { cin >> A.at(i); }
  int ans = 1 << 29;
  int sum = 0;

  REP(i, M) {
    if (A.at(i) < X) {
      ++sum;
    }
  }
  ans = min(ans, sum);

  sum = 0;
  REP(i, M) {
    if (A.at(i) > X) {
      ++sum;
    }
  }
  ans = min(ans, sum);

  cout << ans << endl;

  return 0;
}
