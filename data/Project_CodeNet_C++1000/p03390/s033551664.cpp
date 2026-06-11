#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++){
    long long A, B;
    cin >> A >> B;
    long long N = sqrt(A * B);
    if (N * N == A * B) {
      N = 2 * N - 2;
      if (A == B) N++;
    }
    else {
      N = 2 * N;
      if ((N / 2) * (N / 2 + 1) >= A * B) N--;
    }
    cout << N - 1 << endl;
  }
}