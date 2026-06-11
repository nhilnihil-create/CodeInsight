#include <bits/stdc++.h>
using namespace std;

int main() {

  int a,b,k,x,y;
  cin >> a >> b >> k;
  
  x = a;
  y = b;
  
  if ( b - a < k * 2 ){
    while(x <= b){
      cout << x << endl;
      x++;
    }
  }else{
    while(x < a + k ){
      cout << x << endl;
      x++;
    }
    while( y - (k - 1) <= b ){
      cout << y - ( k - 1) << endl;
      y++;
    }
  }      
  
}

