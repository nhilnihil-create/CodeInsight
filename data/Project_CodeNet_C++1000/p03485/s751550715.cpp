#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b;
  c = (a + b) / 2;
  if ((a % 2 == 1 && b % 2 == 0)||(a % 2 == 0 && b % 2 == 1))
    c ++;
  cout << c << endl;
}