#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  long long K;
  cin >> S >> K;
  int last1 = -1;
  for (int i = 0; i < S.length(); i++) {
    if (S[i] - '0' != 1) break;
    last1 = i;
  }
  if (K <= ++last1) {
    cout << '1';
  }
  else {
    cout << S[last1];
  }
  return 0;
}