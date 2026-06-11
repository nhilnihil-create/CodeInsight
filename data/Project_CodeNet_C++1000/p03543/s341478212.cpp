#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, x1, x2, x3, x4;
  cin >> n;

  x1 = n/1000;
  x2 = (n%1000)/100;
  x3 = (n%100)/10;
  x4 = n%10;
  
  if ( ( x1 == x2 ) && ( x1 == x3 ) ||
       ( x2 == x3 ) && ( x2 == x4 ) ) {
	cout << "Yes" << endl;
  } else {
	cout << "No" << endl;
  }
}