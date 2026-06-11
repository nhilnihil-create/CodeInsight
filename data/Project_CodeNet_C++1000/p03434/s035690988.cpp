#include <bits/stdc++.h>
using namespace std;

int main() {
  //データの数Nセーブ用のSを宣言
  int N, S, A=0;
  
  //データの数を入力
  cin >> N;
  
  //一列の行列を宣言dataが読み込み用data_newが書き込み用
  vector<int> data(N);
  
  
  //データを読み込み
  for(int i = 0;i < N; i++){
    cin >> data.at(i);
  }
  
  
  //データを大きい順に並べる
  for(int i = 0;i < N-1 ; i++){
    for(int j = i+1 ; j < N; j++){
      if( data.at(i) < data.at(j) ){
        S = data.at(j);
        data.at(j) = data.at(i);
        data.at(i) = S;
      } 
    }
  }
  
  //奇数と偶数で場合分け
  if( N % 2 == 0){
    for(int i = 0; i < N  ; i += 2){
      A += data.at(i) - data.at (i + 1);
    }
  }
  else{
    int i ;
    for(i = 0; i < N - 1 ; i += 2){
      A += data.at(i) - data.at (i + 1);
    }
    A += data.at(i);
  }
  
  cout << A << endl;
}
  