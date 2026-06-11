#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int ans;
  if(a+b >= 2*c) {
    if(x<y) {
      if(2*y*c < 2*x*c + (y-x)*b) ans = 2*y*c;
      else ans = 2*x*c + (y-x)*b;
    }
    else {
      if(2*x*c < 2*y*c + (x-y)*a) ans = 2*x*c;
      else ans = 2*y*c + (x-y)*a;
    } 
  }
  else {
    ans = a*x + b*y;
  }
  cout << ans << endl;
}