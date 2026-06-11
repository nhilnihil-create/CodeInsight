// ABC 076 B- Addition and Multiplication

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); i++)

int main() {
  int N, K;
  cin >> N >> K;

  int j = 1;
  rep(i, N) {
    if (j * 2 < j + K) {
      j *= 2;
    }
    else {
      j += K;
    }
  }
  cout << j << endl;
}
