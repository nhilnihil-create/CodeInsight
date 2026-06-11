#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  int N, D, X;
  cin >> N >> D >> X;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  int ans = 0;
  for (int day = 1; day <= D; day++) {
    REP(i, N) {
      int j = 0;
      while (j * A[i] < 101) {
        if (1 + j * A[i] == day) {
          ans++;
          break;
        }
        j++;
      }
    }
  }
  ans += X;
  cout << ans << endl;
}