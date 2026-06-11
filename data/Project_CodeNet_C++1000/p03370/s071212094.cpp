#include <bits/stdc++.h>
using namespace std;

int main() {
 
  int n,x,m,a;
  cin >> n >> x;
  
  a = x;
  
  for ( int i = 0; i < n; i++){
    cin >> m;
    x -= m;
    if ( a > m ){
      a = m;
    }
  }
  
  cout << n + ( x / a ) << endl;   
  
}
