#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  
  int retval = 0;
  if (2*C < A+B) { // ABピザを買った方がお得
    if (X<Y) { // ABピザを2X枚(A:X枚, B:X枚)、Bを(Y-X)枚
      retval += C*2*X;
      retval += min(B,2*C)*(Y-X);
    }
    else {
      retval += C*2*Y;
      retval += min(A,2*C)*(X-Y);
    }
  }
  else {
    retval += A*X + B*Y;
  }
  
  cout << retval << endl;
    
  
  return 0;
}