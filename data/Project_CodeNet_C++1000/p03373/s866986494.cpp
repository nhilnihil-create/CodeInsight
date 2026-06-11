#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,X,Y,ans=0;
  cin >> A >> B >> C >> X >> Y;
  int min_c = min(X,Y);
  //X,Yうち小さい方の数まで買う。
  if((A + B) <= 2*C){
    ans += A * min_c + B * min_c;
  }else if((A + B) > 2*C){
    ans += 2 * min_c * C;
  }
  //足りない分は値段を見て決める。
  ans += A <= 2*C ? A * (X - min_c) : 2 * C * (X - min_c);
  ans += B <= 2*C ? B * (Y - min_c) : 2 * C * (Y - min_c);
  
  cout << ans << endl;
}