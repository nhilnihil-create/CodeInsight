#include<bits/stdc++.h>
using namespace std ;

int main(){
  int A , B , K ; 
  cin >> A >> B >> K ; 
  int N = max(A , B ) ; 
  int cnt = 0 ; 
  
  for(int i = N ; i >= 1 ; i--){
    if(A%i == 0 && B%i == 0 ){
      cnt++ ; 
    }
    //cout << i << " " << cnt << endl ; 
    if( cnt == K){
      cout << i << endl ; 
      return 0 ; 
    }
  }
  
}