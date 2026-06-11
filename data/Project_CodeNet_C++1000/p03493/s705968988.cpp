#include <bits/stdc++.h>
using namespace std;

int main() {
  int input;
  int a, b, c;
  
  cin >> input;
  
  a = input % 2;
  b = (input - a) / 10 % 2;
  c = (input - (a + 10 * b)) / 100 % 2;
  
  cout << a + b + c << endl;
  
}