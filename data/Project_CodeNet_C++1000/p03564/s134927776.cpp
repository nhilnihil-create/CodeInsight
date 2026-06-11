#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int init = 1;

  for (int i= 0; i < N; i++) {
    if (2*init < init + K) {
      init = 2*init;
    } else {
      init = init + K;
    }
  }

  cout << init;
}
