#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define println(msg) cout << msg << endl

typedef struct Rec {
  int x;
  int y;
  ll h;
} Rec;

int main() {
  // 入力
  int N;
  cin >> N;

  vector<Rec> data(N);
  for (int i = 0; i < N; i++) {
    cin >> data.at(i).x;
    cin >> data.at(i).y;
    cin >> data.at(i).h;
  }
  
  // 計算
  int cx = 0;
  int cy = 0;
  int ch = 0;
  
  Rec m = *min_element(
    data.begin(), data.end(),
    [](Rec &l, Rec &r) -> bool { return l.h > r.h; });
  ll hmin = m.h;
  ll hmax = hmin + 200;
  
  for (int y = 0; y <= 100; y++) {
    for (int x = 0; x <= 100; x++) {
      for (ll h = hmin; h <= hmax; h++) {
        bool flag = true;
        for (auto &t : data) {
          if (t.h != max(h - abs(x - t.x) - abs(y - t.y), (ll)0)) {
            flag = false;
            break;
          }
        }
        if (flag) {
          cx = x;
          cy = y;
          ch = h;
        }
      }
    }
  }
  
  // 出力
  cout << cx << " " << cy << " " << ch << endl;
}
