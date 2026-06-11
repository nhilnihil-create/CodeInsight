#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int dis(int l, int r, const vector<P> &A) {
  return abs(A[l].first - A[r].first) + abs(A[l].second - A[r].second);
}
int main() {
  int H, W, D;
  cin >> H >> W >> D;
  vector<P> A(H * W + 10);
  REP(i, H) REP(j, W) {
    int a;
    cin >> a;
    A[a] = P(i + 1, j + 1);
  }
  vector<vector<int>> m(D);
  REP(i, D) {
    int a = i;
    if (a == 0) a = D;
    while (a <= H * W) {
      m[i].push_back(a);
      a += D;
    }
  }
  vector<vector<ll>> wa(D);
  REP(i, D) {
    wa[i].push_back(0);
    REP(j, m[i].size() - 1) {
      wa[i].push_back(dis(m[i][j], m[i][j + 1], A) + wa[i][j]);
    }
  }
  int Q;
  cin >> Q;
  REP(i, Q) {
    int l, r;
    cin >> l >> r;
    cout << -wa[l % D][(l - 1) / D] + wa[r % D][(r - 1) / D] << endl;
  }
}