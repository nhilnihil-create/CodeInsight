#include<bits/stdc++.h>
using namespace std ; 


int main() {
  string S ; 
  cin >> S ; 
  int N = S.size() ;
  int M = 1000  ;
  
  for(int i = 0 ; i < N-2 ; i++){
    int right = 0 ; 
    int cnt = 0 ; 
    
    for(int j = i ; j < i+3 ; j++){
      char A = S.at(j) ; 
      if(j == i ) right = 100*(A - '0') ; 
      if(j == i+1) right = 10*(A - '0') ; 
      if(j == i+2) right = A - '0' ; 
      cnt += right ; 
    }
    right = abs(cnt - 753) ; 
    M = min(M , right) ;  
  }
  
  
  cout << M << endl ;  
  
}