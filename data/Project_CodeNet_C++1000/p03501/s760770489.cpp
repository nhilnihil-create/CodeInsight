#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int pln1 = n * a, pln2 = b;
  if (pln1 <= pln2) {
    cout << pln1 << endl;
  } else {
    cout << pln2 << endl;
  }
}