#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N , K ; 
  cin >> N >> K ; 
  int min_A = N+1 ; 
  int cnt = 0 ; 
  
  vector<int> A(N) ; 
  for(int i = 0  ; i < N ; i++) {
    cin >> A.at(i) ; 
    if(min_A > A.at(i)){
      min_A = A.at(i)  ;
      cnt = i; 
      
    }
  }
  int ans = 0 ; 
  if((N-1)%(K-1) == 0 ){
  	cout << (N-1)/(K-1) << endl ;
  }
  else{
      	cout << (N-1)/(K-1)  + 1<< endl ;
  }
}