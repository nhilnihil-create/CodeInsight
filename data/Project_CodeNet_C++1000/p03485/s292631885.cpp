#include <bits/stdc++.h>
using namespace std;

int main () {
  int a;
  int b;
  cin >> a >> b;
  int c = (a + b) % 2;
  if (c == 1) {
  cout << (a + b) / 2 + 1 << endl;
  }
  else {
   cout << (a + b) / 2 << endl;
  }
}