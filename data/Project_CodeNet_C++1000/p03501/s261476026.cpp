#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B, x;
  cin >> N >> A >> B ;
  x = N * A;
  if (x > B) {
    cout << B << endl;
  } else if (x < B) {
    cout << x << endl;
  } else cout << x << endl;
  return 0;
}