#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ; 
  cin >> N ; 
  vector<int> A(N) ; 
  for(int i = 0 ; i < N ; i++) cin >> A.at(i) ; 
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end()) ;
  
  int SUM_L = 0 ; 
  for(int i = 1 ; i < N ; i++) SUM_L += A.at(i) ; 
  
  if(SUM_L > A.at(0)){
    cout << "Yes" << endl ;
  }
  else{
    cout << "No" << endl ; 
  }
}