#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);

  int A, B;
  cin >> A >> B;

  cout << max(max((A + B), (A - B)), A * B )<< "\n";

  return 0;
}