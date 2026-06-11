#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a = N % 10;
  int b = ((N - a) / 10) % 10;
  int c = ((N - a - 10 * b) / 100) % 10;
  int d = ((N - a - 10 * b - 100 * c)) / 1000;
if ( (a == b && b == c) || (b == c && c == d)) {
  cout << "Yes" << endl;
}
  else {
    cout << "No" << endl;
  }
}