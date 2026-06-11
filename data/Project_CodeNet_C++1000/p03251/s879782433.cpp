#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<int> xv(n);
  vector<int> yv(m);
  rep(i, n) cin >> xv[i];
  rep(i, m) cin >> yv[i];
  for(int i = x + 1; i <= y; i++) {
    bool flag_x = true;
    bool flag_y = true;
    rep(j, n) {
      if(xv[j] >= i) flag_x = false;
    }
    rep(j, m) {
      if(yv[j] < i) flag_y = false;
    }
    if(flag_x && flag_y) {
      cout << "No War" << endl;
      return 0;
    }
  }
  cout << "War" << endl;
  return 0;
}
    