#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, T, P1, P2;
  cin >> T >> A >> B;
  P1 = A*T;
  P2 = B;
  
  if(A*T < B) {
    cout << P1 << endl;
  } else if( P1 > P2) {
    cout << P2 << endl;
  } else {
    cout << P2 << endl;
  }
}