#include <iostream>
using namespace std;

int sum_digit( int n ){
  int wa = 0;
  while( n > 0 ){
    wa += n%10;
    n /= 10;
  }
  return wa;
}
    
int main(){
  int a, b, n, sum, min = 1000;
  cin >> n;
  
  for( a = 1; a <= n/2; a++ ){
    b = n-a;
    sum = sum_digit(a) + sum_digit(b);
//	cout << a << " " << b << " " << sum << endl;
    if( sum < min ){
      min = sum;
    }
  }
  cout << min << endl;

  return 0;
}