#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B, K;
  cin >> A >> B >> K;
  for(int i=A; i<A+K; i++){
    if(i<=B){
      cout << i << endl;
    }
  }
  for(int i=B-K+1; i<=B; i++){
    if(A+K<=i){
      cout << i << endl;
    }
  }
}