#include <bits/stdc++.h>
using namespace std;

int wa(int a, int b) {
  int awa = 0, bwa = 0;
  while (a > 0) {
    awa += a % 10;
    a /= 10;
  }
  while (b > 0) {
    bwa += b % 10;
    b /= 10;
  }
  return awa + bwa;
}

int main() {
  int n;
  cin >> n;
  int minsum = 10000;
  for (int a = 1; a < n; a++) {
    int b = n - a;
    minsum = min(minsum, wa(a, b));
  }
  cout << minsum;
}