#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,X,Y,sum1,sum2,sum3,sum4;
  cin >> A >> B >> C >> X >> Y;
  sum1=A*X+B*Y;
  sum2=max(X,Y)*2*C;
  sum3=2*X*C+max(Y-X,0)*B;
  sum4=2*Y*C+max(X-Y,0)*A;
  cout << min(min(sum1,sum2),min(sum3,sum4)) << endl;
}
 