#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int64_t K;
  cin >> S >> K;
  for (int i = 0; i < K; i++) {
    if (S.at(i) != '1') {
      cout << S.at(i) << endl;
      break;
    }
    else if (i == K - 1) {
      cout << 1 << endl;
    }
  }
}