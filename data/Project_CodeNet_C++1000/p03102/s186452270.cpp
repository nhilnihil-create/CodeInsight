#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M, C;
  cin >> N >> M >> C;
  vector<int> B(M);
  int cnt = 0;
  for (int i = 0; i < M; i++) cin >> B[i];
  for (int i = 0; i < N; i++) {
    int productAB = 0;
    for (int j = 0; j < M; j++) {
      int A;
      cin >> A;
      productAB += A * B[j];
    }
    if (productAB + C > 0) cnt++;
  }
  cout << cnt << endl;

  return 0;
}
