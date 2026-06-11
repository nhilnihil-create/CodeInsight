#include<bits/stdc++.h>
using namespace std ;

int main(){
  string S ; 
  cin >> S ; 
  int T = 0 ; 
  int max = 0 ; 
  int N ; 
  N = S.size() ; 
  
  for(int i = 0 ; i < N ; i++){
    if(S.at(i) == 'A' || S.at(i) == 'C' || S.at(i) == 'G'|| S.at(i) == 'T' ){
      T++ ; 
    }
    else{
      if(T >= max){
        max = T ; 
      }
      T = 0 ; 
    }
  }
  
  if(max <= T){
    cout << T << endl ; 
    return 0 ; 
  }
  
  cout << max << endl; 

}

