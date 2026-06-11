#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int H,W;
  cin >> H >> W;

  string S[H];
  rep(cnt, H) {
    cin >> S[cnt];
  }
  
  rep(cnt_h,H) {
    rep(cnt_w,W) {
      if (S[cnt_h].at(cnt_w) != '#') {
        char x = 0;
        for (int i = -1; i <= 1; ++i) {
          for (int j = -1; j <= 1; ++j) {
            if ( (0 <= cnt_h + i) && (cnt_h + i < H) &&
                 (0 <= cnt_w + j) && (cnt_w + j < W) ) {
              x += (S[cnt_h + i].at(cnt_w + j) == '#');
            }
          }
        }
        switch(x) {
          case 0:
            S[cnt_h].at(cnt_w) = '0';
            break;
          case 1:
            S[cnt_h].at(cnt_w) = '1';
            break;
          case 2:
            S[cnt_h].at(cnt_w) = '2';
            break;
          case 3:
            S[cnt_h].at(cnt_w) = '3';
            break;
          case 4:
            S[cnt_h].at(cnt_w) = '4';
            break;
          case 5:
            S[cnt_h].at(cnt_w) = '5';
            break;
          case 6:
            S[cnt_h].at(cnt_w) = '6';
            break;
          case 7:
            S[cnt_h].at(cnt_w) = '7';
            break;
          case 8:
            S[cnt_h].at(cnt_w) = '8';
            break;
        }
      }
    }
  }
  
  rep(cnt, H) {
    cout << S[cnt] << endl;
  }  
}