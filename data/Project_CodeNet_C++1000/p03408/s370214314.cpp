#include <bits/stdc++.h>
using namespace std;

int main() {
  
  //文字列の箱の用意
  int N , M;
  cin >> N;
  vector <string> s (N);
  vector <string> t (M);
  
  //得点判定用num_maxとnum_now
  int num_max=0, num_now=0;
  
  //文字列の格納
  for(int i = 0;i < N; i++){
   	cin >> s.at(i); 
  }
  
  cin >> M;
  for(int i = 0;i < M; i++){
   	cin >> t.at(i); 
  }
  
  
  //判定用プログラム
  //判定用プログラム加算
  for(int i=0;i < N; i++){
    num_now=1;
    for(int j=i+1;j < N;j++){

      if(s.at(i) == s.at(j)){
        num_now++;
      }
    }
    
    //判定用プログラム減少
    for(int j=0;j < M;j++){
      if(s.at(i) == t.at(j)){
        num_now--;
      }
    }
     //最大値の置き換え
    if(num_max < num_now){
      num_max = num_now;
    }
  }
  
  //出力
  cout << num_max << endl;
  
  
}

