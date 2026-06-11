#include<bits/stdc++.h>
using namespace std ;

int main(){
  string S ; 
  cin >> S ; 
  int N = S.size() ; 
  long long K ; cin >> K ;
  char ans  ; 
  
  for(long long i = 0 ; i < K ; i++){
    ans = S.at(i) ; 
    if(ans != '1' ){
      break ; 
    }
  }
  cout << ans << endl ; 
}