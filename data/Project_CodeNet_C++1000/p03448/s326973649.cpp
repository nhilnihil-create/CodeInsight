#include <bits/stdc++.h>
using namespace std;
int main() {
  
  //必要な箱を用意
  int A;  //500円の枚数
  int B;  //100円の枚数
  int C;  //50円の枚数
  int Aim; //目標の金額
  int sum; //合計金額
  int count = 0; //何通りあるか
  
  //入力部
  cin >> A;
  cin >> B;
  cin >> C;
  cin >> Aim;
  
  for (int i = 0; i < A+1; i++){
    sum = 0; //初期化
    sum = 500*i;
    if (sum == Aim){
      count++;
      break;
    }
    if (sum > Aim)
      break;
    
    for (int j = 0; j < B+1; j++){
      sum = 0;
      sum = 500*i + 100*j;
      if (sum == Aim){
      count++;
      break;
      }
     if (sum > Aim)
      break;
      
      for (int k = 0; k < C+1; k++){
        sum = 0;
      	sum = 500*i + 100*j +50*k;
        if (sum == Aim){
      	count++;
      	break;
        }
        if (sum > Aim)
          break;
      }
    }
  }
  
  cout << count <<endl;//出力部
}