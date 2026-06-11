#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> c(10, vector<int>(10));
void wf(){
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      for(int k = 0; k < 10; k++){
        c.at(j).at(k) = min(c.at(j).at(k), c.at(j).at(i) + c.at(i).at(k));
      }
    }
  }
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++) cin >> c.at(i).at(j);
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++) cin >> a.at(i).at(j);
  }
  
  wf();
  
  int ans = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      int now = a.at(i).at(j);
      if(now < 0) continue;
      ans += c.at(now).at(1);
    }
  }
  
  cout << ans << endl;
}