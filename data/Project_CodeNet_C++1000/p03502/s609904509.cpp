#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, n, f = 0;
  cin >> N;
  n = N;
  
  while ( n > 0 ) {
    f += n % 10;
    n = n / 10;
  }
  
  if ( N % f == 0 ) {
    
    cout << "Yes" << endl;
  }
  else {
    
    cout << "No" << endl;
  }
  
}