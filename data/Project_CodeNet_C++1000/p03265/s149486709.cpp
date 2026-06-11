#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  
  int x,y;
  x = abs(a - c);
  y = abs(b - d);
  
  if ( a <= c && b <= d ){
    cout << c - y << " " << d + x << " " << a - y << " " << b + x << endl;
  }else if ( a <= c && b >= d ){
    cout << c + y << " " << d + x << " " << a + y << " " << b + x << endl;
  }else if ( a >= c && b <= d ){
    cout << c - y << " " << d - x << " " << a - y << " " << b - x << endl;
  }else if ( a >= c && b >= d ){
    cout << c + y << " " << d - x << " " << a + y << " " << b - x << endl;
  }  
 
}