#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, M;
  string S, T;
  cin >> N >> M >> S >> T;
  long long gcd = __gcd(N, M);
  long long ans = N / gcd * M;
  for (int i = 0; i < gcd; i++) {
    if (S[i * N / gcd] != T[i * M / gcd]) {
      ans = -1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}