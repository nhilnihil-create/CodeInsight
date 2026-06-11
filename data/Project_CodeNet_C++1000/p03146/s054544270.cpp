#include<bits/stdc++.h>
using namespace std ;

int main(){
  int s ; 
  cin >> s ; 
  map<int , int > M ; 
  M[s]++ ; 
  int cnt = 0 ; 
  
  while(M[s] != 2){
 
    
    
    if( s%2 == 0 ) {
      s = s/2 ; 
    }
    else if( s%2 != 0 ) {
      s = 3*s + 1 ; 
    }
    M[s]++ ; 
    cnt++ ;
  }
  cnt++ ; 
  cout << cnt << endl ;
  
}