#include <bits/stdc++.h>
using namespace std;

int main() {

  int A, B, I, J, H, S, M, X;
  cin >> A >> B;
  X = 0;
  for(int i = A; i <= B; i++){
  M = i / 10000;
  S = (i % 10000) / 1000;
  J = (i % 100) / 10;
  I = (i % 10);
  if(M == I && S == J){
   X++;
  }
  }
cout << X << endl;
}
