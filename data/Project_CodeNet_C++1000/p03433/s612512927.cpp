#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, x;
  cin >> n >> a;
  x = n % 500 - a;
  if (x > 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}