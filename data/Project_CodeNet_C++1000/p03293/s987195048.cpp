#include<bits/stdc++.h>
using namespace std ;

int main(){
  string S , T ; 
  cin >> S >> T ; 
  string U ; 
  int N = S.size() ; 
  
  for(int i = 1 ; i <= N ; i++){
    U = S.substr(N-i,i) + S.substr(0,N - i ) ; 
    //cout << U << endl ;
    if(U == T){
      cout << "Yes" << endl;
      return 0 ; 
    }
  }
  
  cout << "No" << endl ; 
}
