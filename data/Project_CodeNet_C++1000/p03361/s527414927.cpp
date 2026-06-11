#include <bits/stdc++.h>
#define rep(i, to) for (int i = 0; i < (to); ++i)
#define repf(i, from, to) for (int i = (from); i < (to); ++i)
#define unless(cond) if (!(cond))
using namespace std;
using ll = long long;
template <typename T>
using V = vector<T>;
template <typename T, typename U>
using P = pair<T, U>;

int main() {
  int h, w;
  cin >> h >> w;
  V<string> canvas(h, "");
  V<int> dh = {-1, 0, 0, 1};
  V<int> dw = {0, -1, 1, 0};

  rep(i, h){
    cin >> canvas[i];
  }

  bool can = true;
  rep(hi, h) {
    rep(wi, w) {
      if(canvas[hi][wi] != '#') {
        continue;
      }

      bool have_adjacent_black = false;
      rep(i, dh.size()) {
        int hj = hi + dh[i];
        int wj = wi + dw[i];

        if(hj >= 0 && hj < h && wj >= 0 && wj < w) {
          if(canvas[hj][wj] == '#') {
            have_adjacent_black = true;
            break;
          }
        }
      }

      if(!have_adjacent_black) {
        can = false;
        break;
      }
    }
  }

  if(can) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}