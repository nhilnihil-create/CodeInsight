#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int main() {
  
  int n ;
  cin >>n ;

  int ans = 0 ;
  int i = 1 ;

  while(1){
      int ans = i*i ;
      if(ans>n) break ;
      i++ ;
  }

  cout << (i-1)*(i-1) << endl ;  
  
}