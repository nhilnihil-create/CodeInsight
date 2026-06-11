#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  int x;
  
  cin >> a;
  x = a / 100 + a / 10 % 10 + a % 100 % 10;
  cout << x << endl; 
}