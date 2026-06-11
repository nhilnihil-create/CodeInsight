#include <bits/stdc++.h>
using namespace std;
// XOR[0, 2^M)= (M==1) ? 1
//                     : 0;
int main(){
  int M,K;
  cin >> M >> K;

  int ub= 1<<M;
  if(K>=ub){
    cout << -1 << endl;
  }
  else if(M==1){
    if(K==0){
      cout << 0 <<" "<< 0 <<" "<< 1 <<" "<< 1 << endl;
    }
    else{
      cout << -1 << endl;
    }
  }
  else{
    for(int i=0; i<ub; i++){
      if(i != K){
        cout << i <<" ";
      }
    }
    cout << K <<" ";
    for(int i=ub-1; i>=0; i--){
      if(i != K){
        cout << i <<" ";
      }
    }
    cout << K << endl;
  }
}