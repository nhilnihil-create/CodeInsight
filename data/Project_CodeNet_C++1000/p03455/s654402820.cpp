#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int a, b;
  cin >> a >> b;
  int c, d;
  c = a % 2;
  d = b % 2;
  
  if (c == 1 && d == 1) {
    cout << "Odd" << endl;
  }
  
  else {
    cout << "Even" << endl;
  }
}