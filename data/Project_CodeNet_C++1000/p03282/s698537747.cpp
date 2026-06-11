#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  long long K;
  cin >> S >> K;

  int one = 0;
  for (size_t i = 0; i < S.size(); ++i) {
    if (S[i] != '1') {
      break;
    }
    ++one;
  }

  if (K <= one) {
    cout << 1 << endl;
  } else {
    cout << S[one] << endl;
  }
}
