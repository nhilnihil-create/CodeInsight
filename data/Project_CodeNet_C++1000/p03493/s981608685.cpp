#include <bits/stdc++.h>
using namespace std;

int main() {
  // ここにプログラムを追記
  int a;
  cin >> a; 
  cout << (a - a%100)/100 + (a%100 - a%10)/10 + a%10 << endl;
}