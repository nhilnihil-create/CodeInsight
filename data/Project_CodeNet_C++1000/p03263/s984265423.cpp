#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w; cin >> h >> w;
  vector<vector<int>> mp(h, vector<int>(w));
  vector<int> x1, x2, y1, y2;
  int cnt = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> mp[i][j];
    }
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w-1; j++){
      if(mp[i][j] % 2){
        mp[i][j]--;
        mp[i][j+1]++;
        y1.push_back(i+1); x1.push_back(j+1);
        y2.push_back(i+1); x2.push_back(j+2);
        cnt++;
      }
    }
  }
  for(int i = 0; i < h-1; i++){
    if(mp[i][w-1] % 2){
      mp[i][w-1]--;
      mp[i+1][w-1]++;
      y1.push_back(i+1); x1.push_back(w);
      y2.push_back(i+2); x2.push_back(w);
      cnt++;
    }
  }
  cout << cnt << endl;
  for(int i = 0; i < cnt; i++){
    cout << y1[i] << " " << x1[i] << " " << y2[i] << " " << x2[i] << endl;
  }
}