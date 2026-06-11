#include "bits/stdc++.h"
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int a = max(max(A, B), C);
  int b = min(min(A, B), C);
  if (C != a && C != b) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
