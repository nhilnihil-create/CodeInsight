#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  int c = N * A;

  if (c <= B) cout << c << endl;
  else cout << B << endl;
}