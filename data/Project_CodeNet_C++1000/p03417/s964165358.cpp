#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t N, M;
  cin >> N >> M;
  if (N == 2 && M == 1) {
    cout << 0 << endl;
  }
  if (N == 2 && M == 1) {
    cout << 0 << endl;
  }
  if (N == 1 && M == 1) {
    cout << 1 << endl;
  }
  if (N == 2 && M == 2) {
    cout << 0 << endl;
  }
  if (N < 2 && M > 2) {
    cout << M - 2 << endl;
  }
  if (N > 2 && M < 2) {
    cout << N - 2 << endl;
  }
  if (N == 2 && M > 2) {
    cout << 0 << endl;
  }
  if (N > 2 && M == 2) {
    cout << 0 << endl;
  }
  if (N > 2 && M > 2) {
    cout << (N - 2) * (M - 2) << endl;
  }
}