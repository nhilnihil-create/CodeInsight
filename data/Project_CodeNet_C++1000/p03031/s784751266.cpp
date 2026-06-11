#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, M;
  cin >> N >> M;
  vector<int> k(M), p(M);
  vector<vector<int>> s(M, vector<int>(N));
  for (int i = 0; i < M; ++i) {
    cin >> k[i];
    for (int j = 0; j < k[i]; j++) cin >> s[i][j];
  }
  for (int i = 0; i < M; i++) cin >> p[i];
  
  //bit全探査
  int out=0;
  for (int bit = 0; bit < (1 << N); bit++) {
    int check = 0;
    for (int i = 0; i < M; i++) {
      int cnt = 0;
      for (int j = 0; j < N; ++j) {
        if (bit & (1 << s[i][j])) {
          cnt++;
        }
      }
      if (cnt % 2 == p[i]) {
        check++;
      }
    }
    if (check == M) out++;
  }
  cout << out << endl;
  return 0;
}