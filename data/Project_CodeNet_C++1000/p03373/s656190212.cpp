#include "bits/stdc++.h"
using namespace std;

int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int sum = 0;
  if(A + B > C * 2){
    int k = min(X, Y);
    sum = C * 2 * k;
    X -= k;
    Y -= k;
  }
  /*
  if(A > C * 2){
    sum += 2 * C * X;
  }else{
    sum += A * X;
  }
  if(B > C * 2){
    sum += 2 * C * Y;
  }else{
    sum += B * Y;
  }
*/
  sum += (A > C * 2) ? 2 * C * X : A * X;
  sum += (B > C * 2) ? 2 * C * Y : B * Y;

  cout << sum << endl;
}