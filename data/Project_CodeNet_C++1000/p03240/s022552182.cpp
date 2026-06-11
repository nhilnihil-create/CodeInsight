#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)

void solve() {
  int N;
  cin >> N;
  vector<int> vx(N), vy(N), vh(N);
  rep(i, 0, N) cin >> vx[i] >> vy[i] >> vh[i];
  int Max = 101;

  rep(y, 0, Max) {
    rep(x, 0, Max) {
      int h = -1;

      rep(i, 0, N) {
        if (vh[i] > 0) {

          int tmp = vh[i] + abs(y - vy[i]) + abs(x - vx[i]);
          if (h == -1) {
            h = tmp;
          } else {
            if (h != tmp) {
              h = -2;
              break;
            }
          }
        }
      }
      if (h == -2) continue;
      
      rep(i, 0, N) {
        if (vh[i] == 0) {
          int tmp = abs(y - vy[i]) + abs(x - vx[i]);
          if (h > tmp) {
            h = -2;
            break;
          }
        }
      }
      if (h == -2) continue;
      cout << x << " " << y << " " << h << endl;
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}