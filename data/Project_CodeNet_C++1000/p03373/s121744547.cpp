#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int ans =max(max(A,B),C)*(X+Y);
//  int Acount=0, Bcount =0, Ccount = 0;

  for(int i=0; i<=max(X,Y)*2; i += 2){
      int Xp = X-i/2;
      int Yp = Y-i/2;
      if(Xp < 0) Xp=0;
      if(Yp < 0) Yp=0;
      ans = min(C*i + A*Xp + B*Yp, ans);
  }
  cout << ans << endl;
  return 0;
}