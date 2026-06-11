#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> f(h);
  for (int i = 0; i < h; i++){
    cin >> f.at(i);
  }

  vector<int> x = {1, 0, -1, 0};
  vector<int> y = {0, 1, 0, -1};
  
  
  bool ans = true;
  
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      if (f.at(i).at(j) == '.'){
        continue;
      }
      else{
        bool t = false;
        for (int k = 0; k < 4; k++){
          int iy = i + y.at(k);
          int jx = j + x.at(k);
          if (iy < 0 || iy >= h){
            continue;
          }
          if (jx < 0 || jx >= w){
            continue;
          }
          if (f.at(iy).at(jx) == '#'){
            t = true;
            break;
          }
        }
        if (t == false){
          ans = false;
          break;
        }
      }
      if (ans == false){
        break;
      }
    }
  }
  
  if(ans){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}