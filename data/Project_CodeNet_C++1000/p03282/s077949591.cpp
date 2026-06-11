#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  long K;
  cin >> S >> K;
  long N = S.size();
  if (K <= N) {
    for (int i = 0; i < K; i++) {
      if (S.at(i) != '1') return cout << S.at(i) << "\n", 0;
    }
    return cout << '1' << "\n", 0;
  } else {
    for (char c : S) if (c != '1') return cout << c << "\n", 0;
  }
}