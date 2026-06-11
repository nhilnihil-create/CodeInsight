#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  cin >> a;
  int b = a % 2;
  int c = (a - b) / 10 % 2;
  int d = ((a - b) / 10 - c) / 10 % 2;
  cout << b + c + d << endl;
}