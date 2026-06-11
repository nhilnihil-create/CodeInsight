#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  int s;
  cin >> a >> b >> c;
  
  s = a * b;
  
  if (s < c) {
    cout << s << endl;
  } else {
    cout << c << endl;
  } 
}
