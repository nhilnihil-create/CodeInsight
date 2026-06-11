#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Move {
 public:
  int x1;
  int y1;
  int x2;
  int y2;
} move;
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> A(H, vector<int>(W));
  REP(i, H) REP(j, W) cin >> A[i][j];
  queue<Move> Q{};
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (i == H - 1 && j == W - 1) break;
      int div = i % 2 == 0 ? 1 : -1;
      int tmp = i % 2 == 0 ? j : W - 1 - j;
      if (A[i][tmp] % 2 == 1) {
        Move m;
        m.x1 = tmp, m.y1 = i;
        m.x2 = tmp;
        m.y2 = i;
        if (j == W - 1) {
          m.y2 += 1;
        } else {
          m.x2 += div;
        }
        Q.push(m);
        A[m.y1][m.x1] -= 1, A[m.y2][m.x2] += 1;
      }
    }
  }
  cout << Q.size() << endl;
  while (!Q.empty()) {
    Move m = Q.front();
    Q.pop();
    cout << m.y1 + 1 << " " << m.x1 + 1 << " " << m.y2 + 1 << " " << m.x2 + 1
         << endl;
  }
}