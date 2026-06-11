#include <iostream>
#include <functional>
using namespace std;

int main() {
  int A,B,C,X,Y,plice,ans;
  cin >> A >> B >> C >> X >> Y;
  
  cout << min(A*X + B*Y,min( C*2*X + B*max(Y-X,0), min(C*2*Y + A*max(X-Y,0),C*2*max(X,Y))) ) << endl;
  
}