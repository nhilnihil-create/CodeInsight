#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >> N;
  
  int64_t a = 2;
  int64_t b = 1;
  int64_t c = 3;

  if (N == 1) {
    cout << b << endl;
  }
  else {
    for (int i = 1; i < N; i++) {
      c = b + a ;
      a = b;
      b = c;
    }
    cout << c << endl;    
  }
  
  
return 0;
}