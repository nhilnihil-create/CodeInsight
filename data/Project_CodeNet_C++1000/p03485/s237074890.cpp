#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, x, ret;
  
  cin >> a >> b;
  x = a + b;
  ret = x / 2;
  
  if (x % 2 == 1) {
  	ret += 1;
  }
  
  cout << ret << endl;
}
