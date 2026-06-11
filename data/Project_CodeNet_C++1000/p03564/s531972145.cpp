#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  
  int A = 1;
  int counter = 0;
  
  for(int i = 0; i < N; i++){
    if(A < K){
      A *= 2;
    }else{
      A += K;
    }
  }

  cout << A << endl;
  
}