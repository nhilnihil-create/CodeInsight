#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int N;
int X[110];
int Y[110];
int H[110];

int main(){
  cin >> N;
  rep(i, N) cin >> X[i] >> Y[i] >> H[i];

  int init;
  rep(i, N){
    if (H[i] > 0){
      init = i;
      break;
    }
  }

  int h;
  int ans_x, ans_y, ans_h;
  rep(x, 101){
    rep(y, 101){
      // initは高度が0より大きい地点を表す
      h = H[init] + abs(X[init] - x) + abs(Y[init] - y);

      // 条件式を満たしているかどうかのチェック
      bool check = true;
      rep(i, N){
        // maxを消去する
        if (H[i] > 0){
          if (h - abs(X[i] - x) - abs(Y[i] - y) != H[i]) check = false;
        }
        else {
          if (h - abs(X[i] - x) - abs(Y[i] - y) > 0) check = false;
        }
      }

      // 答えは一意に定まる
      if (check){
        ans_x = x;
        ans_y = y;
        ans_h = h;
      }
    }
  }

  cout << ans_x << " " << ans_y << " " << ans_h << endl;
}
