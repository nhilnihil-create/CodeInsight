#include <bits/stdc++.h>
using namespace std;

int define(int data){
   int ans=0;
  for (int i=0;i<5;i++){
    ans += data % 10;
    data /= 10;
  }
  return ans;
}

int main() {
  int N;//データ
  int A,B;//上限:A,下限:B
  int ans = 0; //答え
  
  //入力部
  cin >>N>>A>>B;
  
  //計算部:0～9999までの足し算
  for (int i=1;i <= N ;i++){
    int norm = 0;
    norm = define(i);
    if(A <= norm && B >= norm)
      ans += i;
  }
  //出力部
  cout << ans<< endl;
}

    
  
  
  
    
  
  
