#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int res = 1;
  for (int i = 0; i < N; i++) {
    if (res >= K) {
      res += K*(N - i);
      break;
    }
    else res *= 2;
  }
  cout << res << endl;
}