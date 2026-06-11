#include <bits/stdc++.h>
using namespace std;

int main() {
  int a = 0, x = 0, y = 0, z = 0;
  cin >> a;
  
  x = a/100; y = (a%100)/10; z = (a%100)%10;
  
  cout << x + y + z << endl;
}
