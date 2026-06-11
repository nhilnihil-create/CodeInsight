#include<bits/stdc++.h>
using namespace std ;

int main(){
  int X ; 
  cin >> X ; 
  int a , b ;
  cin >> a >> b ;
  int ans = 0 ; 
  
  for(int i = 1 ; i <= X ; i++){
    int j = i ; 
    int cnt = 0 ; 
    for(int k = 0 ; k < 5 ; k++ ){
      cnt += j%10 ; 
      j /= 10 ; 
    }
    
    if( cnt >= a && cnt <= b ){
      ans += i ; 
    }
  }
  
  
 cout << ans << endl ; 
}