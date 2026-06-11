#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  int d,e,f;
  cin >> a;
  
  d = a / 100; //100の位
  f = a % 10; // 1の位
  e = (a - (100*d) - f)/10; //10の位
  
  cout << d+e+f << endl;
}