#include <iostream>
using namespace std;

int main(){
  int a, b, c, x, y, z;
  int i, imin, sum, min = 10000000000;

  cin >> a >> b >> c >> x >> y;

  if( x>y ){
    z = x;
  }else{
    z = y;
  }
 
  for( i=0; i<=z; i++ ){
    if( i<=x && i<=y ){
      sum = (x-i)*a + (y-i)*b + i*c*2;
    }else if( i>x ){
      sum = (y-i)*b + i*c*2;
    }else{
      sum = (x-i)*a + i*c*2;
    }
      
    if( sum < min ){
      min = sum;
      //imin = i;
      //      cout << i << " " << sum << " " << min << endl;
    }
  }
  cout << " " << min << endl;
  return 0;
}