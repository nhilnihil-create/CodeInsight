#include <bits/stdc++.h>
using namespace std;

main(void){
  int A,B,C,X,Y;cin >> A >> B >> C >> X >> Y;
  int ans1=A*X + B*Y;
  int ans2=2*C*max(X,Y);
  int ans3=2*C*min(X,Y)+((Y< X) ? A * (X-Y) : B * (Y - X));
  cout << min({ans1,ans2,ans3});
}
  