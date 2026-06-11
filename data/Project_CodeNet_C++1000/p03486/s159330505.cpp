#include<bits/stdc++.h>
using namespace std ;

int main(){
  string S , T ;
  cin >> S >> T ; 
  
  int N = S.size() ; 
  int M = T.size() ; 
  
  sort(S.begin(),S.end()) ;
  sort(T.begin(),T.end()) ;
  reverse(T.begin(),T.end()) ; 
  
  for(int i = 0 ; i < N ; i++){
    
    if(S < T){
      cout << "Yes" << endl ;
      return 0 ; 
    }
    else{
      cout << "No" << endl ;
      return 0 ; 
    }
  }
  
}