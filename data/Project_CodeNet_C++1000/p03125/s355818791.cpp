#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin >> a;
  int b;
  cin >> b;
  bool d = false;
  for (int i = 1; i <= b; i = i + 1) {
    if (b%i == 0) {
      if (i == a) {
        d = true;
      }
    }
  }
  if (d) {
    cout << a + b << endl;
  } else {
    cout << b - a << endl;
  }
}
  