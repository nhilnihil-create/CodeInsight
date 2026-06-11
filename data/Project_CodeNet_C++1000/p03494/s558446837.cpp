#include <bits/stdc++.h>
using namespace std;

int main() {
  int N=0, A=0, B=0, C=0;
  cin >> N;
  
  for(int i=0; i<N; i++){
    cin >> A;
    if(A%2==0){
      B = 0;
      while(A%2 == 0){
        A = A/2;
        B++;
      }
    }
    if(i==0){
      C = B;
    }
    else if(C > B){
    C = B;
    }
  }
  cout << C << endl;
}