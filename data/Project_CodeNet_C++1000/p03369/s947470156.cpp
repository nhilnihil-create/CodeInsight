#include<bits/stdc++.h>
using namespace std ;

int main(){
  string S ; 
  
  cin >> S ; 
  int N = S.size() ;
  int P = 700 ; 
  
  for(int i = 0 ; i < N ; i++){
    if(S.at(i) == 'o'  ){
      P = P + 100 ; 
    }
  
  }
  
  cout << P << endl ; 
  
}