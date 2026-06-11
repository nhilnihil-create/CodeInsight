#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
ll c[10][10];
ll dis[10];
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
void f(int i, ll d, int lim, int first) {
  if (lim < d) return;
  REP(j, 10) {
    if (i == j) continue;
    if (j == 1) {
      chmin(dis[first], d + c[i][j]);
      continue;
    }
    f(j, d + c[i][j], lim, first);
  }
}
int main() {
  int H, W;
  cin >> H >> W;
  REP(i, 10) { dis[i] = 1e10; }
  REP(i, 10) REP(j, 10) { cin >> c[i][j]; }
  REP(i, 10) {
    dis[i] = c[i][1];
    f(i, 0, c[i][1], i);
  }
  ll ans = 0;
  REP(i, H) REP(j, W) {
    int a;
    cin >> a;
    if (a == -1 || a == 1) continue;
    ans += dis[a];
  }
  cout << ans << endl;
}