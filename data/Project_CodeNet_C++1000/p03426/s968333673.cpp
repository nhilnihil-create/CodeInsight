#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int H, W, D;
  cin >> H >> W >> D;
  int A[H][W];
  REP(i, H) REP(j, W) cin >> A[i][j];
  pair<int, int> route[H*W];
  REP(i, H) {
    REP(j, W) {
      route[A[i][j] - 1] = make_pair(i, j);
    }
  }
  int cost[H*W*3];
  REP(i, D) cost[i] = 0;
  for (int i = D; i < H*W; i++) {
    cost[i] = abs(route[i].first - route[i-D].first) + abs(route[i].second - route[i-D].second);
  }
  REP(i, H*W) {
    cost[i+D] += cost[i];
  }



  int Q;
  cin >> Q;
  REP(i, Q) {
    int L, R;
    cin >> L >> R;
    cout << cost[R-1] - cost[L-1] << endl;
  }

  return 0;
}