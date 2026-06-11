#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if (a > 8 || b > 8 || a > 2 * b || b > 2 * a) {
    cout << ":(" << endl;
  }
  else {
    cout << "Yay!" << endl;
  }
}
