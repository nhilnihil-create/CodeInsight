#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, D, X;
  cin >> N >> D >> X;
  for (int i = 0; i < N; ++i) {
    long long A;
    cin >> A;
    long long start = 1;
    while (start <= D) {
      ++X;
      start += A;
    }
  }
  cout << X << endl;
}
    