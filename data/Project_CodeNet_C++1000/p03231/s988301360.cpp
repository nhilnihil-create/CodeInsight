#include <iostream>
#include <numeric>
using namespace std;

int main() {
  int N, M;
  string S, T;
  cin >> N >> M >> S >> T;
  auto X = lcm<long long>(N,M);
  auto Y = gcd(N,M);

  bool b{1};
  for (int i = 0; i != Y; ++i) {
    if (S[i*N/Y] != T[i*M/Y]) {
      b = 0;
      break;
    }
  }
  cout << (b ? X : -1) << endl;
}
