#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int a,b,c,d,x,y;
  cin >> a >> b >> c >> d;
  
  if ( a >= b ){
    x = b;
  }else{
    x = a;
  }
  
  if ( c >= d ){
    y = d;
  }else{
    y = c;
  }
  
  cout << x + y << endl;
  
}

