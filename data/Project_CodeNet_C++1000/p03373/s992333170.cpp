#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 0;
  if(a+b<=2*c)  ans = a*x+b*y; 
  else{
    if(x>=y) ans = y*2*c + (x-y)*a;
    else     ans = x*2*c + (y-x)*b;
  }
  if(ans > max(x,y)*2*c) ans = max(x,y)*2*c;
  cout << ans << endl;
  return 0;
}