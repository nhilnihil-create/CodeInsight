#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int a, b;
  cin >> a >> b;
  
  // 上半分白，下半分黒
  vector<vector<char>> x(100, vector<char>(100, '#'));
  for(int i = 0; i < 50; i++){
    for(int j = 0; j < 100; j++){
      x.at(i).at(j) = '.';
    }
  }
  
  // 足りない分だけ上半分に黒，下半分に白を1マスずつ独立させて置く
  int white = 1, black = 1, i = 0, j = 0;
  
  // 黒を追加
  while(black < b){
    x.at(i).at(j) = '#';
    black++;
    if(j < 98){
      j += 2;
    }
    else{
      i += 2;
      j = 0;
    }
  }
  
  // 白を追加
  i = 51;
  j = 0;
  while(white < a){
    x.at(i).at(j) = '.';
    white++;
    if(j < 98){
      j += 2;
    }
    else{
      i += 2;
      j = 0;
    }
  }
  
  // 出力
  cout << "100 100" << "\n";
  for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
      cout << x.at(i).at(j);
    }
    cout << "\n";
  }
}