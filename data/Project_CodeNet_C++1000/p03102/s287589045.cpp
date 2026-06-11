#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, C;
  cin >> N >> M >> C;
  int res = 0;
  vector<int> B(M);
  for (int i = 0; i < M; ++i) cin >> B[i];
  for (int i = 0; i < N; ++i) {
    int sum = C;
    for (int j = 0; j < M; ++j) {
      int a; cin >> a;
      sum += a * B[j];
    }
    if (sum > 0) ++res;
  }
  cout << res << endl;
}