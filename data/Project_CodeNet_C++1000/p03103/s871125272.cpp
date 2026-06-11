#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() {
  int N, M;
  cin >> N >> M;
  vector<P> A(N);
  REP(i, N) cin >> A[i].first >> A[i].second;
  sort(A.begin(), A.end());
  ll ans = 0, num = 0;

  REP(i, N) {
    REP(j, A[i].second) {
      ans += A[i].first;
      num++;
      if (num == M) {
        cout << ans << endl;
        return 0;
      }
    }
  }
}