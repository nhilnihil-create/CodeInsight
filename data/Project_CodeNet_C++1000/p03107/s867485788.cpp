#include<bits/stdc++.h>
using namespace std ;

int main(){
  string S ; 
  cin >> S ; 
  int N = S.size() ; 
  
  int cnt_R = 0 ;
  int cnt_B =  0;
  for(int i = 0 ; i < N ; i++){
    if(S.at(i) == '1' ){
      cnt_B++ ; 
    }
    else{
      cnt_R++ ; 
    }
  }
  cout << min(cnt_R , cnt_B)*2 << endl ; 
  
}