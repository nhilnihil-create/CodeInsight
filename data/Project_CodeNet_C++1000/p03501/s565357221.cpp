#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B,x;
  cin >> N >> A >> B;
  if (N * A >= B) x = B;
  else x = N * A;
  cout << x << endl;
  return 0;
}