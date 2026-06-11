#include<bits/stdc++.h>
using namespace std ; 

int main(){
  int N ; 
  cin >> N ; 
  vector<long long> A(N) ; 
  for(int i = 0 ; i < N ; i++) cin >> A.at(i) ; 
  
  long long  M = gcd(A.at(0) , A.at(1)) ; 
  for(int i = 2 ; i < N ; i ++){
    M = gcd(M,A.at(i)) ; 
  }
  
  cout << M << endl;
}