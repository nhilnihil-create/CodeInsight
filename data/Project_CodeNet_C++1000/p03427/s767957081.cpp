#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int Z = S.size();
  bool b = true;
  
  if (Z == 1) {
    cout << S << endl;
    return 0;
  }
  
  for (int i = 1; i < Z; i++) {
    if (S[i] != '9') {
      b = false;
      break;
    }
  }
  
  int max = S[0] - '0' + 9 * (Z-1);
  if (b) {
    cout << max << endl;
    return 0;
  }
  cout << max - 1 << endl;
}