#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  long long N, M;
  cin >> N >> M;
  if (N > M) swap(N, M);
  if (N == 1) {
    cout << abs(M - 2) << endl;
  } else {
    cout << (N - 2) * (M - 2) << endl;
  }
}
