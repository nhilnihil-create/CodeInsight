#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  
  int  A , B , C , D , N ;
  
  cin >>  N ; 
  
  A = N / 1000 ;                                   
  
  B = ( N - A * 1000 ) / 100 ;                     
  
  C = ( N - A * 1000 - B * 100 ) / 10 ;            
  
  D = N % 10 ;            
  
  if (B != C) {
    cout << " No " << endl ;
  }
  
  else if ( A == B ) {
    cout << " Yes " << endl ;   
  }
  
  else if ( D == B ) {
    cout << " Yes " << endl ;
  }
  
  else  {
    cout << " No " << endl ;
  }  
  
}