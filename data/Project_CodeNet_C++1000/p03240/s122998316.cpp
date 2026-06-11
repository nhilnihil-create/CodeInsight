#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  ll N;
  cin >> N;
  vector<int> x(N), y(N), h(N);
  REP(i, N) cin >> x[i] >> y[i] >> h[i];
  ll H;
  int id;
  REP(i, N) {
    if (h[i] != 0) {
      id = i;
      continue;
    }
  }
  REP(Cx, 101) REP(Cy, 101) {
    H = h[id] + abs(x[id] - Cx) + abs(y[id] - Cy);
    if (H <= 0) continue;
    bool t = true;
    REP(i, N) {
      int tmp = H - abs(x[i] - Cx) - abs(y[i] - Cy);
      tmp = max(0, tmp);
      if (tmp != h[i]) {
        t = false;
      }
    }
    if (t) {
      cout << Cx << " " << Cy << " " << H << endl;
    }
  }
}