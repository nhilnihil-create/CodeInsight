#include<bits/stdc++.h>
using namespace std ; 

int main(){
  int D , N ; 
  cin >> D >> N ; 
  long long P = 0 ; 
  for(int i = 1 ; i <= N ; i++){
    if(D == 1){
      P += 100 ; 
      if(P == 10000) P += 100 ; 
    }
    if(D == 2) {
      P += 100*100 ; 
      if(P == 1000000) P += 10000 ; 
    }
    if(D == 0){
      P = i ; 
      if(P == 100) P++ ;
    }
  }
  
  cout << P << endl ; 
}