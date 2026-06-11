#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  int half_N = N/2;
  if (N % 2 == 0) {
    cout << N / 2 * N / 2 << endl;
  } else {
    cout << (half_N + 1) * half_N << endl;
  }
}