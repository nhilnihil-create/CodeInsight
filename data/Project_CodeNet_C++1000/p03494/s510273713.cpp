#include "bits/stdc++.h"
using namespace std;

int main(){
  //使用する変数の初期化
  int n, a, c;
  //数値が何個あるか変数nに代入
  cin >> n;
  //動的配列初期化
  vector<int> v;
  //変数nの数値分ループ
  for(int i = 0; i < n; i++){
    //2で割った回数のカウンタ初期化
    c = 0;
    //2で割る数値を変数aに代入
    cin >> a;
    //2で割り切れる間ループ
    while(a % 2 == 0){
      //2で割った回数+1
      c++;
      //変数aの数値を最新化
      a = a / 2;
    }
    //動的配列の最後尾に変数aを2で割り切れた回数を追加
    v.push_back(c);
  }
  //動的配列の中身を小さい順に並び変える
  sort(v.begin(), v.end());
  //動的配列の先頭を出力
  cout << v[0];
}