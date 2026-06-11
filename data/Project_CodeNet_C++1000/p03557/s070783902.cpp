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
int binary_search(vector<int> &A, int x, bool t) {
  int l = -1, r = A.size();
  while (r - l > 1) {
    int mid = l + (r - l) / 2;
    if ((t && x > A[mid]) || (!t && x >= A[mid])) {
      l = mid;
    } else {
      r = mid;
    }
  }
  // t=trueなら、たかい
  return r;
}
int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N), C(N);
  REP(i, N) cin >> A[i];
  REP(i, N) cin >> B[i];
  REP(i, N) cin >> C[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  ll ans = 0;
  REP(i, N) {
    int tmp = B[i];
    ll tmp2 = binary_search(A, tmp, true);
    ll tmp3 = binary_search(C, tmp, false);
    tmp3 = N - tmp3;
    ans += tmp2 * tmp3;
  }
  cout << ans << endl;
}