#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, K;
  cin >> A >> B >> K;
  
  for(int i=0; i<K; i++){
    if(A+i<=B){
      cout << A+i << endl;
    }
  }
  
  for(int i=K-1; i>=0; i--){
    if(B-i>A+K-1){
      cout << B-i << endl;
    }
  }
}