#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a = n / 1000;
  int b = (n - a * 1000) / 100;
  int c = (n - a * 1000 - b * 100) / 10;
  int d = n - a * 1000 - b * 100 - c * 10;

  if ((a == b && b == c) || (b == c && c == d)) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}