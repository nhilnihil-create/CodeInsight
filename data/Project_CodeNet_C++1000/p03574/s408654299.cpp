#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  
  //表の取得
  vector<vector<char>> v(h, vector<char>(w));
  for(int i=0; i<h; i++) {
    string s;
    cin >> s;
    for(int j=0; j<w; j++) v[i][j] = s[j];
  }
  
  //012
  //3.4 空マス周囲座標
  //567
  vector<int> dx = {-1, 0, 1, -1, 1, -1, 0, 1}; //横
  vector<int> dy = {-1, -1, -1, 0, 0, 1, 1, 1}; //縦

  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      if(v[i][j] == '#') continue; //爆弾
      
      //空白マスの周囲を検証
      int a, b;
      int count = 0;
      for(int k=0; k<8; k++) {
        a = j+dx[k];
        b = i+dy[k]; 
        if(a<0 || w<=a) continue; //枠外
        if(b<0 || h<=b) continue; //枠外
        if(v[b][a] == '#') count++; //爆弾をカウント
      }
      v[i][j] = char(count+'0');//空マス'.'を数字に置換
    }
  }
  
  //出力
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      cout << v[i][j];
      if(j==w-1) cout << endl;
    }
  }
  return 0;
}