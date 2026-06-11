#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  
  string s = "";
  for (int i = 0; i < h; i++) {
    string si;
    cin >> si;
    s += si;
  }
  
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s.at(i*w+j) == '#') cout <<"#";
      else{
        
        // 周囲の爆弾の数を数える
        int count_bomb = 0;
        for (int k = -1; k <= 1; k++) {
          for (int l = -1; l <= 1; l++) {
            if (i+k >= 0 && i+k < h && j+l >= 0 && j+l < w){
              int pos = (i+k)*w + (j+l);
              if (s.at(pos) == '#') count_bomb += 1;
            }
            
          }
        }
        cout << count_bomb;
        
      }
      
  	}
    cout << endl;
  }
}
