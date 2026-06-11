#include<bits/stdc++.h>
using namespace std;
int main(){
  int A, B, K;
  cin >> A >> B >> K;
  for(int i=0; i<K; i++){
    if(i %2 == 0){
      if(A %2 == 1){
        A--;
      }
     B += A / 2;
     A = A / 2;
    }
    if(i %2 != 0){
      if(B %2 == 1){
        B--;
      }
     A += B / 2;
     B = B / 2;
    }
  }
  cout << A << endl;
  cout << B << endl;
}