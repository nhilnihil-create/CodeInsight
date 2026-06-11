#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, a, b, x;
  cin >> n >> a >> b;

  if ( n*a >= b ) {
	x = b;
  } else {
 	x = n*a;
  }
    cout << x << endl;
}