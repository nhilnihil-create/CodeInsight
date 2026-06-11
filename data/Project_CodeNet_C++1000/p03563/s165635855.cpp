#include <bits/stdc++.h>
using namespace std;

int main() {
  int R;
  int G;
  double b;

  cin >> R;
  cin >> G;

  if (R < 0) {
    exit (1);
  }

  if (G > 4500) {
    exit (1);
  }

  if (G <= 0) {
    b = -1 * R;
  } else {
    b = 2 * G - R;
  }

  cout << b << endl;
}

