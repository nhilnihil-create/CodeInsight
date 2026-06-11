#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int A = n * a;

  if (A >= b) {
    cout << b << endl;
  }
  else {
    cout << A << endl;
  }
}