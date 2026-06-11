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
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  sort(A.begin(), A.end());
  bool t = true;
  while (t) {
    t = false;
    REP(i, N) {
      if (A[i] % A[0] == 0) continue;
      A[i] = A[i] % A[0];
      t = true;
    }
    sort(A.begin(), A.end());
  }
  cout << A[0] << endl;
}