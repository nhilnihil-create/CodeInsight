#include <bits/stdc++.h>
using namespace std;

int main() {
  double a,b;
  double diff;
  double h;
  cin >> a >> b;
  
  // 13-8=5(1+...5メートルの塔)
  diff = b - a - 1;
  
  // 等差数列
  h = diff * (diff+1) / 2;
  cout << h - a;
}
