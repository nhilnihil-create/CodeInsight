#include <bits/stdc++.h>
using namespace std;

int main() {
  string C[2];
  cin >> C[0] >> C[1];

  bool isMatch = C[0][0] == C[1][2] && C[0][1] == C[1][1] && C[0][2] == C[1][0];

  cout << (isMatch ? "YES" : "NO") << endl;
}