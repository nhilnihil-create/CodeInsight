#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,K;
  cin >> A >> B >> C >> K;
  for(int i=1; i<=K; i++){
    if(A == max({A,B,C})) A = A*2;
    if(B == max({A,B,C})) B = B*2;
    if(C == max({A,B,C})) C = C*2;
  }
  cout << A+B+C << endl;
}
