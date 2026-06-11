#include <bits/stdc++.h>
using namespace std;

int main() {
  // ここにプログラムを追記
  int a, b;
  cin >> a;
  b = a % 2; 
  b += a / 2 % 2;
  b += a / 2 / 2 % 2;
  cout << b << endl;
}