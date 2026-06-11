#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int N, M, L;
  string S, T;
  cin >> N >> M >> S >> T;
  L = N * M / __gcd(N, M);
  for (long long int i = 0; i < __gcd(N, M); i++) {
    long long int x = N * i / __gcd(N, M), y = M * i / __gcd(N, M);
    if (S.at(x) != T.at(y)) {
      L = -1;
      break;
    }
  }
  cout << L << endl;
}