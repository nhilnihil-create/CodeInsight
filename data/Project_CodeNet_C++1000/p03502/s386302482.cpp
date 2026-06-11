#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N, X,R,S,P,A;
  cin >> N;
  P = N;
  S=0;
for(int i=0; i < 8; i++){
    R=1;
  for(int r=1; r<8-i; r++){
    R *=10; }
  X = P/R;
  S = S+X;
  P -= X*R;
}
  A = N/S;
if(A*S==N){
  cout << "Yes" << endl;
}
  else{
    cout << "No" << endl;
  }
}