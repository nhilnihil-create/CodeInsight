#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  a = a + b;
  if(a % 2 != 0) {
    a = a / 2 + 1;
  } else {
    a = a / 2;
  }
  cout << a << endl;
}