#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a, b, c, d;
  cin >> N;
  a = N / 1000;
  b = (N - 1000 * a) / 100;
  c = (N - 1000 * a - 100 * b) / 10;
  d = N % 10;

  if ((a == b && b == c &&c == d) || (a == b && b == c) || (b == c && c == d))
    cout << "Yes" << endl;
  else
    cout << "No" <<endl;
}