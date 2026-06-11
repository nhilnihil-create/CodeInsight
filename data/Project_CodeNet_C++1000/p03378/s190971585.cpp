#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M, X;
  cin >> N >> M >> X;
  vector<int> A(M);
  for (int i = 0; i < M; i++) cin >> A[i];
  int costToZero = 0;
  int costToN = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < M; j++) {
      if (i < X && i == A[j]) costToZero++;
      else if (i == A[j]) costToN++;
    }
  }
  int ans = costToZero < costToN ? costToZero : costToN;
  cout << ans << endl;
  return 0;
}