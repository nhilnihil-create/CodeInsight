#include<bits/stdc++.h>
using namespace std ;
 
int main() {
  int X ; 
  cin >> X ; 
  int ans = 0 ; 
  
  for(int i = 1 ; i <= X ;i++){
    for(int j = 2 ; j <= 100 ; j++){
      int P = pow(i , j) ; 
      if(P <= X){
        ans = max(P , ans) ; 
      }
    }
  }
  cout << ans << endl ; 
}