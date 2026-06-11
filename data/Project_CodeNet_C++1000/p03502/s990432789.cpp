#include <bits/stdc++.h>
using namespace std;

int main() {
  int N ;
  cin >> N ;
  int N2 = N;
  int k=0 ;
  for ( int i = 0; i<8 ; i++ ){
    k += N % 10;
    N = N/10;
  }
  if ( N2 % k == 0 ){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}