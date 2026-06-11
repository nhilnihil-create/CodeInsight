#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int l = a + b, r = c + d;
  if (l == r) {
    cout << "Balanced\n";
  } else if (l < r) {
    cout << "Right\n";
  } else {
    cout << "Left\n";
  }
  
  return 0;
}
