#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  
  int t,x,y,p,a,b,dt,dx,dy,hantei;
  
  p = 0;
  a = 0;
  b = 0;
  hantei = 1;
  
  for ( int i = 0; i < n; i++){
    cin >> t >> x >> y;
    dt = t - p;
    dx = abs(x - a);
    dy = abs(y - b);
    if ( dt < dx + dy ){
      hantei = 0;
    }else if ( dt > dx + dy && ( dt - dx - dy ) % 2 != 0 ){
      hantei = 0;
    }
    if ( hantei == 1 ){
      p = t;
      a = x;
      b = y;
    }else{
      cout << "No" << endl;
      return 0;
    }
  }
  
  cout << "Yes" << endl;
  return 0;

}