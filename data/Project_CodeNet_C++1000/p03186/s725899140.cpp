#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c;
  d = min(a+b+1,c) + b;
  cout << d << endl;
}