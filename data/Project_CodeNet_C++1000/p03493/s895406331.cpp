#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin >> a;
  int b1 = 0, b2= 0, b3= 0;
  b1 = a / 100;
  b2 = (a-b1*100) / 10;
  b3 = a-b1*100-b2*10;
  cout << b1+b2+b3 << endl;
}