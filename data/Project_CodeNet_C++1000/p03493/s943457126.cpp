#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int a;
  int x, y, z;
  cin >> a;
  x = a/100;
  y = (a-x*100)/10;
  z = (a-x*100-y*10)/1;
  
  cout << x+y+z << endl;
}