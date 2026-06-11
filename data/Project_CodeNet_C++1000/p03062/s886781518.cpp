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
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  int minuscnt = 0;
  REP(i, N) if (A[i] < 0) minuscnt++;
  ll ans = 0;
  REP(i, N) ans += abs(A[i]);
  if (minuscnt % 2 == 0) {
  } else {
    REP(i, A.size()) { A[i] = abs(A[i]); }
    sort(A.begin(), A.end());
    ans -= 2 * A[0];
  }
  cout << ans << endl;
}