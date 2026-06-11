#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B, x;
  cin >> N >> A >> B;
  if (N * A <= B) x = N * A;
  else x = B;
  cout << x << endl;
}