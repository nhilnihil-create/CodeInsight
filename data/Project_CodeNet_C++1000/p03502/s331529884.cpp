#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a, b, c, d, i, j;
  cin >> N;
  a = N;
  d = 0;
  for (i = 0; 0 < a; i++){
      a /= 10;
  }
  a = N;
  while (i > 0) {
    b = 1;
    for (j = 0; j < i - 1; j++){
      b *= 10;
    }
    c = a / b;
    d += c;
    a -= c * b;
    i--;
  }
  if (N % d == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}