#include<bits/stdc++.h>
using namespace std ; 


int main(){
  string S ; 
  cin >> S ; 
  int N = S.size() ; 
  int cnt = 0 ; 
  
  for(int i = 0 ; i < N ; i++){
    if(S.at(i) == '+'){
      cnt++ ; 
    }
    else{
      cnt-- ; 
    }
  }
  
  cout << cnt << endl;
  
}