#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  
  int num_remain = max(X,Y)-min(X,Y);
  
  if(A+B <= 2*C){
    cout << A*X +B*Y << "\n";
  }else if(A+B>2*C && ((A>=2*C && X>Y) || (B>=2*C && X<Y))){
    cout << 2*C*max(X,Y) << "\n";
  }else if(X>=Y){
    cout << A*(X-Y) + 2*C*Y << "\n";
  }else{
    cout << B*(Y-X) + 2*C*X << "\n";
  }
}

  