#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  int* x = (int*) calloc(100, sizeof(int));
  cin >> N;
  if (N == 0) {
    cout << '0';
    return 0;
  }
  for (int i = 0; N != 0; i++, N -= N & 1, N /= -2) {
    x[i] = N & 1;
  }
  int foo = 99;
  for (; x[foo] == 0; foo--);
  for (; foo >= 0; foo--) {
    cout << x[foo];
  }
  return 0;
}