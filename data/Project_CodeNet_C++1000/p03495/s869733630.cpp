#include<bits/stdc++.h>
using namespace std ; 

int main(){
  int N , K ; 
  cin >> N >> K ;
  vector<int> C(N);
  for(int i = 0 ; i < N ; i++){
    int A ; 
    cin >> A ; 
    A-- ; 
    C.at(A)++ ; 
  }

  //cout << C.at(1)
  sort(C.begin(),C.end()) ;
  reverse(C.begin(),C.end()) ;
  int ans = 0 ; 
  int cnt = 0 ; 
  for( int p : C ){
    if(K > cnt){
      ans += p ; 
      cnt++ ; 
    }
    else break ; 
  }
  
  cout << N - ans << endl ; 
}