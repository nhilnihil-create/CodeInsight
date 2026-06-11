#include <bits/stdc++.h>
using namespace std;
int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  c *= 2;
  int ans = min(x,y)*min(a+b,c);
  if(x-y > 0) ans += min(a, c)*(x-y);
  if(y-x > 0) ans += min(b, c)*(y-x);
  cout << ans << endl;
}