#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  if(n == 1) {
    cout << "1" << endl;
    return 0;
  } else {
    int64_t a, b, c;
    a = 2;
    b = 1;
    int count = 2;
    while (count <= n) {
      c = a+b;
      a = b;
      b = c;
      count++;
    }
    cout << c << endl;
    return 0;
  }
  
}