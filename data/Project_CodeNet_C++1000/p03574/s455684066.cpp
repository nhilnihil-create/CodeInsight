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

// 爆弾マスは-1
// 空きマスは0

int main() {
  int h, w;
  cin >> h >> w;
  V<V<int>> field(h, V<int>(w, 0));
  V<string> s_list;
  s_list.resize(h);

  rep(i, h) {
    cin >> s_list[i];
  }

  rep(hi, h) {
    rep(wi, w) {
      if(s_list[hi][wi] == '#') {
        field[hi][wi] = -1;

        repf(hj, hi - 1, hi + 2) {
          repf(wj, wi - 1, wi + 2) {
            if(hj >= 0 && hj < h && wj >= 0 && wj < w) {
              if(field[hj][wj] == -1) {
                continue;
              }

              field[hj][wj]++;
            }
          }
        }
      }
    }
  }

  rep(hi, h){
    rep(wi, w) {
      if(field[hi][wi] == -1) {
        cout << "#";
      } else {
        cout << field[hi][wi];
      }
    }
    cout << endl;
  }
}