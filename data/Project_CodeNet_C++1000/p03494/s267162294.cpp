#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a, b, c;
  cin >> N;
  b = 9999;
  for (int i = 0; i < N; i++) {
    cin >> a;
    c = 0;
    while (a % 2 == 0) {
      c++;
      a /= 2;
    }
    if (c < b) {
      b = c;
    }
  }
  cout << b << endl;
}