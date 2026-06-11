#include <iostream>
using namespace std;

int main(){
  char a[3];
  int b[3];
  cin >> a;
  for ( int i = 0 ;  i < 3 ; i++ ){
    b[i] = a[i] - '0';
  }
  int n=0;
  for ( int i = 0 ;  i < 3 ; i++ ){
    n+=b[i];
  }

  cout << n;
  return 0;
}