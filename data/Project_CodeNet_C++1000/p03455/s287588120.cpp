#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  string s1, s2;
  s1 = "Even";
  s2 = "Odd";
  cin >> a >> b;
  c = a * b;
  if( c % 2 == 0 ) {
  	cout << s1 << endl;
  } else {
  	cout << s2 << endl;
  }
}