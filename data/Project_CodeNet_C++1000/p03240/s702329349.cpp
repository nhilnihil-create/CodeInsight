#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rrep(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;


int main() {
  int n;
  cin >> n;
  std::vector<int> x(n),y(n),h(n);
  rep(i,n) cin >> x[i] >> y[i] >> h[i];

  rep(posX,101) rep(posY,101) {
    int needH = -1;
    rep(i,n) {
      if (h[i] > 0) {
        int tmp = h[i] + abs(posX-x[i]) + abs(posY-y[i]);
        if (needH == -1) needH = tmp;
        else {
          if (needH != tmp) {
            needH = -2;
            break;
          }
        }
      }
    }
    if (needH == -2) continue;
    rep(i,n) {
      if (h[i] == 0) {
        int dist = abs(posX-x[i]) + abs(posY-y[i]);
        if (needH > dist) {
          needH = -2;
          break;
        }
      }
    }
    if (needH == -2) continue;
    cout << posX << " " << posY << " " << needH << endl;
    return 0;
  }
}
