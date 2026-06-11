#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M;
  cin >> N >> M;
  int A = 1;
  for (int i = 0; i < M; i++) {
    A *= 2;
  }
  int B = 1900 * M + 100 * (N - M);
  cout << A * B << endl;
}