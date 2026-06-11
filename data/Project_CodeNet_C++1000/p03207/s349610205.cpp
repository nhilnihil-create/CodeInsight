#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int e = 0;
  int p = 0;
  for (int i = 0; i < n; i++) {
    int pi; cin >> pi;
    p += pi;
    e = max(e, pi);
  }
  p -= e/2;
  cout << p <<endl;
}