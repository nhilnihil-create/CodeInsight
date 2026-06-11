#include<bits/stdc++.h>
using namespace std;

int main(void){
 
  int n, w, a[9];
  cin >> n;
  w = n;
  for( int i = 0 ; i < 9 ; i++ ){
    int b = 100000000;
    for( int j = 0 ; j < i; j++ ){
      b /= 10;
//      cout << b <<endl;
    }
    a[i] = w / b;
    w -= a[i] * b ;
//    cout << a[i] << "  " << w << endl;
  }
  int m = 0;
  for( int i = 0 ; i < 9 ; i++ ){
    m += a[i];
  }
  if( n % m == 0 ){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}