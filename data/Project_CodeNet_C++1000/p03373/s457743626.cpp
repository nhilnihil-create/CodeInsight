#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  if(2*c <= min(a,b)){
    cout << 2*c*(max(x,y)) << endl;
  }
  else if(2*c > min(a,b) && 2*c <= max(a,b)){
    if(a = min(a,b)){
      int ans = y*2*c;
      if(x>y){
        ans += a*(x-y);
      }
      cout << ans << endl;
    }
    else {
      int ans = 2*c*x;
      if(y>x){
        ans += b*(y-x);
      }
      cout << ans << endl;
    }
  }
  else if(2*c > max(a,b) && 2*c <= (a+b)){
    if(x>y){
      cout << 2*c*y + a*(x-y) << endl;
    }
    else {
      cout << 2*c*x + b*(y-x) << endl;
    }
  }
  else {
    cout << a*x + b*y << endl;
  }
  
     
  return 0;
}
