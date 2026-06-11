#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<P, int> _P;
const int INF = 1e9;
const ll MOD = 1000000007;
_P Ret_P(int y, int x, int num) { return _P(P(y, x), num); }
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int main() {
  int H, W;
  cin >> H >> W;
  vector<string> A(H);
  REP(i, H) { cin >> A[i]; }
  queue<_P> que;
  REP(i, H) REP(j, W) {
    if (A[i][j] == '#') {
      que.push(Ret_P(i, j, 0));
    }
  }
  ll ans = 0;
  while (!que.empty()) {
    _P p = que.front();
    que.pop();
    chmax<ll>(ans, p.second);
    int y = p.first.first, x = p.first.second, score = p.second;
    if (0 < x) {
      int ny = y, nx = x - 1;
      if (A[ny][nx] == '.') {
        A[ny][nx] = '#';
        que.push(Ret_P(ny, nx, score + 1));
      }
    }
    if (x < W - 1) {
      int ny = y, nx = x + 1;
      if (A[ny][nx] == '.') {
        A[ny][nx] = '#';
        que.push(Ret_P(ny, nx, score + 1));
      }
    }
    if (0 < y) {
      int ny = y - 1, nx = x;
      if (A[ny][nx] == '.') {
        A[ny][nx] = '#';
        que.push(Ret_P(ny, nx, score + 1));
      }
    }
    if (y < H - 1) {
      int ny = y + 1, nx = x;
      if (A[ny][nx] == '.') {
        A[ny][nx] = '#';
        que.push(Ret_P(ny, nx, score + 1));
      }
    }
  }
  cout << ans << endl;
}