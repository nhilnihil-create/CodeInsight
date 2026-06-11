#include<bits/stdc++.h>
using namespace std ; 

int main(){
  int N ; 
  cin >> N ; 
  vector<long long> X(N) ; 
  vector<long long> P(N) ; 
  for(int i = 0 ; i < N ; i++) {
    cin >> X.at(i) ;
    P.at(i) = X.at(i) ; 
  }
  sort(X.begin(),X.end()) ;
  
  for(int i = 0 ; i < N ; i++){
    //cout << P.at(i) << " " << X.at((N-1)/2) << endl ; 
    if(P.at(i) <= X.at((N-1)/2) ) cout << X.at(N/2) << endl ; 
    else cout << X.at((N)/2 - 1) << endl ; 
  }
  
}