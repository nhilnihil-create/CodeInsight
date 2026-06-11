#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a = 0;
  int x,y,z;
  cin >> a;
  
  x = a / 100;
  x = x % 2;
  y = a / 10;
  y = y % 2;
  z = a % 2;
   
  cout << x + y + z << endl;
  
  return 0;
}