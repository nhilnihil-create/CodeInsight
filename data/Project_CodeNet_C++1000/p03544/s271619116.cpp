#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int64_t a = 2, b = 1, r = 0;
  if(n == 0) {
    r = a;
  }
  else if(n == 1) {
    r = b;
  }
  else {
    for(int i = 2; i <= n; i++) {
      r = a + b;
      a = b;
      b = r;
    }
  }
  cout << r;
}
