#include<bits/stdc++.h>
using namespace std ; 

int main() {
  int r , D , x ; 
  cin >> r >> D >> x ; 
  int new_x = x ; 
  
  for( int i = 1 ; i <= 10 ; i++ ){
	new_x = r*new_x - D ; 
    cout << new_x << endl ;
  }

  
  
}