#include <bits/stdc++.h>
using namespace std;

int main() {
  char c1, c2, c3, c4;
  cin >> c1 >> c2 >> c3 >> c4;

  if ((c1 == c2 && c2 == c3) || (c2 == c3 && c3 == c4)) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
