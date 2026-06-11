#include <bits/stdc++.h>
using namespace std;

int main() {
  int a[11] = {};
  int b;
  for( int i = 0; i < 4; ++i ) {
    cin >> b;
    a[b]++;
    
  }
  
  if( a[1] == 1 && a[7] == 1 && a[4] == 1 && a[9] == 1 ) cout << "YES";
  else cout << "NO";
  cout << endl;
  
  return 0;
  
}

    
  
  