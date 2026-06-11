#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;

  cin >> n >> a >> b;

  a *= n;

  if (a > b) {
    a = b;
  }
  cout << a << endl;
}
