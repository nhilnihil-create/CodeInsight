#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  int C = 0;
  cin >> A >> B;
  for (int i = A; i <=  B; i++) {
    int b = i / 10000;
    int c = (i - (b * 10000)) / 1000;
    int d = (i - (b * 10000) - (c * 1000)) / 100;
    int e = (i - (b * 10000) - (c * 1000) - (d * 100)) / 10;
    int f = (i - (b * 10000) - (c * 1000) - (d * 100) - (e * 10)) / 1;
    if (i == b + (c * 10) + (d * 100) + (e * 1000) + (f * 10000) && f != 0) {
      C += 1;
    }
    else {
      continue;
    }
  }
  cout << C << endl;
}