#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int N, M; cin >> N >> M;
  vector<int> b(M, 0);
  for (int i = 0; i < N; ++i) {
    int K; cin >> K;
    for (int j = 0; j < K; ++j) {
      int A; cin >> A; --A;
      b[A]++;
    }
  }

  int cnt = 0;
  for (int i = 0; i < M; ++i) {
    if (b[i] == N) ++cnt;
  }
  cout << cnt << endl;
}
