#include <bits/stdc++.h>
using namespace std;

int main() {
  int l;
  cin >> l;
  vector<int> digits;
  while (l > 0) {
    digits.push_back(l % 2);
    l /= 2;
  }
  int n = digits.size();
  int m = n * 2 - 3;
  for (int d : digits) {
    m += d;
  }
  cout << n << " " << m << "\n";
  for (int ni = 1; ni < n; ni++) {
    cout << ni << " " << ni + 1 << " " << 0 << "\n";
    cout << ni << " " << ni + 1 << " " << (1 << (ni - 1)) << "\n";
  }
  int offset = 1 << (n - 1);
  for (int ni = n - 2; ni >= 0; ni--) {
    if (digits[ni]) {
      cout << ni + 1 << " " << n << " " << offset << "\n";
      offset += (1 << ni);
    }
  }
  return 0;
}