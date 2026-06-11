#include <bits/stdc++.h>
using namespace std;
int main(){
 int M, S, J, I;
 int A, B;
  cin >> A >> B;
  int c = 0;
   for(int i = A; i <= B; i++){
    M = i / 10000;
    I = i % 10;
    S = i % 10000 / 1000;
    J = i % 100 / 10;
    if ( M == I && S == J){
      c++;
    }
   }
  cout << c << endl;
}