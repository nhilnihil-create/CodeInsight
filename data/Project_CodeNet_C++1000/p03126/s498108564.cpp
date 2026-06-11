#include<bits/stdc++.h>
using namespace std ; 

int main(){
  int N , M ; 
  cin >> N >> M ; 
  int K ; 
  vector<int> C(M) ; 
  
  for(int i = 0 ; i < M ; i++){
    C.at(i) = 0 ; 
  }
  
  for(int i = 0 ; i < N ; i++){
    cin >> K ; 
    vector<int> A(K) ; 
    
    for(int j = 0 ; j < K ; j++ ){
      cin >> A.at(j) ; 
      C.at(A.at(j)-1)++;
    }
  }
  int cnt = 0 ; 
  for(int i = 0  ; i < M ; i++ ){
    if(C.at(i) == N){
      cnt++ ; 
    }
  }
  cout << cnt << endl ; 
  
}