#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,a,b,c,d;
  cin >> x;
  d = x % 10;
  c = (x % 100 -d)/10;
  b = (x % 1000 -x%100)/100;
  a = (x - x % 1000)/1000;
  
  if (a == b && b == c) {
    cout << "Yes" << endl;
  }
  else if (b == c && c == d) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }

}
