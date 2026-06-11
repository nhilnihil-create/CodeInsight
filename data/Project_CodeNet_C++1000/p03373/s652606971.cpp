#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,X,Y,e=0;
  cin >> A >> B >> C >> X >> Y;
  if(2*C<A+B) e = min(X,Y);
  cout << min(A*X+B*Y+e*(2*C-A-B),max(X,Y)*2*C)<< endl;
}
