#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int ans = 0;
  if(A + B > C*2){
    int m = min(X,Y);
    ans += C*2*m;
    X -= m; Y -= m;

    if(A*X + B*Y > 2*X*C + 2*Y*C){
      ans += 2*X*C + 2*Y*C;
    } else {
      ans += A*X + B*Y;
    }
  } else {
    ans += A*X + B*Y;
  }

  cout << ans << endl;
}
