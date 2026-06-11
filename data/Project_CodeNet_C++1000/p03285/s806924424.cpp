#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool b = false;
  for (int i = 0; i < n / 4 + 1; i++) {
    for (int j = 0; j < n / 7 + 1; j++) {
      if (n == i * 4 + j * 7) b = true;
    }
  }
  if (b) cout << "Yes" << endl;
  else cout << "No" << endl;
}