#include<bits/stdc++.h>
using namespace std ; 

int main(){
  int N ; 
  int T , A ; 
  cin >> N >> T >> A ; 
  vector<double> H(N) ; 
  double cnt = 1001000100 ; 
  int p = 0 ; 
  
  for(int i = 0 ; i < N ; i++) {
    cin >> H.at(i) ; 
    H.at(i) = T - H.at(i)*0.006 ; 
    
    if( abs(H.at(i) - A)  < cnt ){
      p = i ; 
      cnt = abs(H.at(i) - A);
    }
    
  }
  
  cout << p+1 << endl ; 
  
}