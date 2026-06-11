#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a;
  cin >> n >> a;

  for (int i = 0; i <= n / 500; i++) {
    for (int j = 0; j <= a; j++) {
      if (i * 500 + j == n) {
        cout << "Yes" << endl;
        return 0;
  }}}

  cout << "No" << endl;
  return 0;
}