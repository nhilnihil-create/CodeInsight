#include<bits/stdc++.h>
using namespace std ; 

int main() {
  int N , K ; 
  char S ; 
  cin >> N >> K ; 

  for(int i = 1 ; i <= N ; i++){
       cin >> S ;
    
    if( i == K ){
        S = S+32 ;
   		cout << S ; 
    }
    else{
        cout << S ; 
    }
    
  }
cout << endl ; 
}