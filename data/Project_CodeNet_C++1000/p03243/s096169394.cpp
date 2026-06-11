#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x = 111;
  cin >> n;
  for (int i = 1; i < 10; i++) {
    if (n <= x * i) {
      cout << x * i;
      return 0;
    }
  }
}
