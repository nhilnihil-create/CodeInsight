#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  if( a*n > b ){
    cout << b << endl;
  }
  else if( a*n <= b ){
    cout << a*n << endl;
  }
  
}