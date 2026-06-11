#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ; cin >> N ; 
  string S ; cin >> S ; 

  int ans = 0 ; 
  
  for(int i = 1 ; i < N ; i++){
    int cnt = 0 ; 
    
    for(char c = 'a' ; c <= 'z'  ; c++){
      bool left = false , right = false ; 
      
      for(int j = 0 ; j < i ; j++){
        if(S.at(j) == c) left = true ; 
      }
      for(int j = i ; j < N ; j++){
        if(S.at(j) == c) right = true ; 
      }
      
      if(left && right ) cnt++ ; 
    }
    ans = max(ans , cnt ) ; 
  }
  
  cout << ans << endl ; 
}