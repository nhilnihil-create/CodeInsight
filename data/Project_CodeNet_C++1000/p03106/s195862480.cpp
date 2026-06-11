#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,K,Z;
  int Y=0;
  cin >> A >> B >> K;
  for (int X=A; X<=A; X--){
    if (A%X==0 && B%X==0){
      Y++;
      if (Y==K){
        Z=X;
        break;
      }
    }
  }
  cout << Z << endl;
}