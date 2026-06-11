#include <bits/stdc++.h>
using namespace std;
 
int main() {
  // ここにプログラムを追記
  int a;
  cin >> a; 
  cout << a / 100 % 2 + a / 10 % 2 + a / 1 % 2;
}