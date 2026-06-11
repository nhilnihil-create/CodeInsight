#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,X,Y,M,m;
  cin >> A >> B >> C >> X >> Y;
  
  m = A*X + B*Y + C*(X+Y);
  
  for (int i = 0; i <= max(2*X,2*Y); i++) {
    M = max(X-i/2,0)*A + max(Y-i/2,0)*B + i*C;
    if ( M <= m ) {
      m = M; 
    }         
  }
  
  cout << m << endl;
  
}