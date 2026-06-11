#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,n;
  int first,second;
  cin >> n >> a >> b;
  
  first = a * n;
  second = b;
  
  if ( first < second ) {
  	cout << first << endl;
  } else {
  	cout << second << endl;
  }
}