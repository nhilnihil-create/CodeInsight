#include<bits/stdc++.h>
using namespace std ; 

int main(){
  int N  ;
  cin >> N ; 
  vector<int> V(N) , C(N) ; 
  int T=0;
  
  for(int i = 0 ; i < N ; i++){
    cin >> V.at(i) ; 
  }
  
  for(int i = 0 ; i < N ; i++){
    cin >> C.at(i) ; 
  }
    
  for(int i = 0 ; i < N ; i++){
    if( V.at(i) - C.at(i) > 0 ){
      T = T + V.at(i) - C.at(i) ;
    }
  }
  
  cout << T <<endl ; 
  
}
