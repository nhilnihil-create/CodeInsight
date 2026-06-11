#include<bits/stdc++.h>
using namespace std ; 

int main(){
  int N , M , X ; 
  cin >> N >> M >> X ;
  vector<int> B(N) ; 
  
  for(int i=0; i < M ; i++){
    int A ; 
    cin >> A ;
    B.at(A)++ ;  
  }
  int cnt = 0 ; 
  for(int i = 0 ; i < X ; i++){
    if(B.at(i) == 1){
      cnt++ ; 
    }
  }
  
  cout << min(cnt,M-cnt) << endl;
}