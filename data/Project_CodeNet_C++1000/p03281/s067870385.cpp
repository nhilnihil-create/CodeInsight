#include <bits/stdc++.h>
using namespace std;

int yakusu(int x){
  int count =0;
  for(int i=1;i<=x;i++){
    if(x%i==0) count++;
  }
  return count;
}
  

int main(){
  int n ;
  cin >> n;
  int ans =0;
//約数の個数を出力する関数を作る
  
  for(int i=1;i<=n;i+=2){
    if(yakusu(i)==8) ans++;
  }
  
  cout << ans << endl;
}

  
  
