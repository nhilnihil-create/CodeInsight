#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  if (n%2 == 0) {
    n /= 2;
  } else {
    n = n/2 + 1;
  }
  if (n >= m) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}