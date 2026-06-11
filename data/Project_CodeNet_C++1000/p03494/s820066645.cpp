#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int r = 100000;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    int n = 0;
    while (A%2 == 0 && A != 0) {
      A /= 2;
      n += 1;
    }
    if (n < r) r = n;
  }
  cout << r << endl;
}