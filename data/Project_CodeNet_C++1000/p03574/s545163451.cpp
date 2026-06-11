#include <bits/stdc++.h>
using namespace std;

int main(){
  string s = "";
  int h, w;
  cin >> h >> w;
  for (int i = 0;i < h;i++) {
    string sb = "";
    cin >> sb;
    s += sb;
  }
  //cout << s << endl;
  for (int j = 0;j < h;j++) {
    for (int k = 0;k < w;k++) {
      int current = (w * j) + k;
      if(s.at(current)=='#') cout << '#';
      else {
        int up = j;
        int left = k;
        int down = j;
        int right = k;
        int count = 0;
        if( j != 0){
          up--;
        }
        if( k != 0){
          left--;
        }
        if( j != (h -1) ){
          down++;
        }
        if( k != (w-1) ){
          right++;
        }
        for (int l = up;l <= down;l++){
          for (int m = left;m <= right;m++){
            int subcurrent = (w * l) + m;
            if( subcurrent != current){
              if(s.at(subcurrent)=='#'){
                count++;
              }
            }
          }
        }
        cout << count;
      }
    }
    cout << endl;
  }
}