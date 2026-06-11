#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int64_t a = 2; 
  int64_t b = 1;
  
  if (N == 0) {
    cout << a << endl;
  }
  else if (N == 1) {
    cout << b << endl;
  }
  else {
    for (int i = 2; i < N + 1; i++) {
      int64_t tmp = b;
      b = a + b;
      a = tmp;
    }
    cout << b << endl;
  }

  return 0;
}
