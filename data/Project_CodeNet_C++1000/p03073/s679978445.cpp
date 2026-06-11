#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i <(int)(n); i++)
using namespace std;

int main(){
  string S;
  cin >> S;
  
  int N = (int)S.size();
  
  int count_a = 0;
  int count_b = 0;
  
  //0文字目が0 == 偶数マスがゼロになるようにする場合count_a
  rep(i,N){
    if(i % 2 == 0){
      if(S.at(i) == '0')count_a++;
    }
    else{
      if(S.at(i) == '1')count_a++;
    }
  }
  
  //奇数マスがゼロ
  rep(i,N){
    if(i % 2 == 1){
      if(S.at(i) == '0')count_b++;
    }
    else{
      if(S.at(i) == '1')count_b++;
    }
  }
  
  cout << min(count_a,count_b) << endl;
  return 0;
  
  
}