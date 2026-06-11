#include<bits/stdc++.h>
using namespace std ;

int main(){
  int a , b ; 
  cin >> a >> b ; 
  
  int s = b -a ; 
  int left = 1 ; 
  int right = 1 ; 
  for(int i= 2 ; i <= 999 ; i++){
    right += i ; 
    //cout << left << " " << right << endl ; 
    if( right - left  == s){
      cout << left - a << endl; 
      return 0 ; 
    }
    left += i ;
  }
  
}