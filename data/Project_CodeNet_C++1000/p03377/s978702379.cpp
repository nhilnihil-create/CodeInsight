#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);

  int A, B, X;
  cin >> A >> B >> X;

  if (A + B >= X && X >= A)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}