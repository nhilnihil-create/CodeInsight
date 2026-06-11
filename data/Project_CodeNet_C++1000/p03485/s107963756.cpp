#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, z;
  cin >> a >> b;
  if ((a+b) % 2 == 0) {
    z = (a+b) / 2;
  }
  else {
    z = (a+b+1) / 2;
  }
  
  cout << z << endl;
}

