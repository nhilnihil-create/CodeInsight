#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int i, j, k, A,B,C,X,Y,yen=0;
  
  cin >> A >> B >> C >> X >> Y;
  
  
  
  if(2*C<A && 2*C<B){
    if(X>Y){
      cout << 2*C*X;
    }else{
      cout << 2*C*Y;
    }
    return 0;
  }
  
  if(2*C<A){
    yen+=2*C*X;
    if(Y>X){
      Y-=X;
      cout << yen+Y*B;
    } else {
      cout << yen;
    }
    return 0;
  }
  
  if(2*C<B){
    yen+=2*C*Y;
    if(X>Y){
      X-=Y;
      cout << yen+X*A;
    } else {
      cout << yen;
    }
    return 0;
  }
  
  if(2*C >= A+B){
    cout << A*X+B*Y;
    return 0;
  }
  
  if(2*C < A+B){
    if(X<Y){
      yen+=2*C*X;
      Y-=X;
      cout << yen+B*Y;
    } else {
      yen+=2*C*Y;
      X-=Y;
      cout << yen+A*X;
    }
    return 0;
  }
}