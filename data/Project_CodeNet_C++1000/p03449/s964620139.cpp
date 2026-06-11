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
  int N;
  cin >> N;
  vector<vector<int>> A(2, vector<int>(N));
  REP(i, 2) REP(j, N) cin >> A[i][j];
  ll mx = 0;
  REP(i, N) {
    ll num = 0, t = 0;
    REP(j, N) {
      num += A[t][j];
      if (i == j) {
        t++;
        num += A[t][j];
      }
    }
    mx = max(mx, num);
  }
  cout << mx << endl;
}