#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C; //値段用の箱を宣言
  int X,Y; //個数用の箱を宣言
  int ans=9999999999;
  int sum=0;
  
  /////入力部/////
  cin>>A>>B>>C; //金額
  cin>>X>>Y; //個数
 
  for(int i=0;i<=100000;i++){
    sum=2*C*i + A*max(0,X-i) +B*max(0,Y-i);
    if(sum<ans)ans=sum;
  }
  
  cout<<ans<<endl;
  
}
