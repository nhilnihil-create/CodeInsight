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
  vector<vector<int>> c(3, vector<int>(3));
  REP(i, 3) REP(j, 3) cin >> c[i][j];
  REP(i,101) REP(j, 101) REP(k, 101) {
    vector<int> a(3);
    vector<int> b(3);
    a[0] = i, a[1] = j, a[2] = k;
    b[0] = c[0][0] - a[0], b[1] = c[1][1] - a[1], b[2] = c[2][2] - a[2];
    if (b[0] < 0 || b[1] < 0 || b[2] < 0) continue;
    bool t = true;
    REP(l, 3) REP(m, 3) {
      if (c[l][m] != a[l] + b[m]) {
        t = false;
        break;
      }
    }
    if (!t) continue;
    puts("Yes");
    return 0;
  }
  puts("No");
}