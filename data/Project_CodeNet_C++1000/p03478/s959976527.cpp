#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;//データ
  int A,B;//上限:A,下限:B
  int ans = 0; //答え
  
  //入力部
  cin >>N>>A>>B;
  
  //計算部:0～9999までの足し算
  for (int i=0;N >= 1000*i && i<10;i++){
    for (int j=0;N >= 1000*i+100*j && j<10;j++){
      for (int k=0;N >= 1000*i+100*j+10*k && k<10;k++){
        for (int l=0;N >= 1000*i+100*j+10*k+l && l<10;l++){
          if((i+j+k+l)<=B && (i+j+k+l)>=A)
            ans += 1000*i + 100*j +10*k +l;
        }
      }
    }
  }
  
  //計算部:10000のときのみ使用
  if (N == 10000&&A <=1 && B >= 1)
    
    ans+= 10000;
  
  //出力部
  cout << ans<< endl;
}

    
  
  
  
    
  
  
