#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> map(N, vector<bool>(M, false));
  for (int i = 0; i < N; i++) {
    int K;
    cin >> K;
    for (int j = 0; j < K; j++) {
      int like;
      cin >> like;
      map[i][like-1] = true;
    }
  }
  int res = 0;
  for (int i = 0; i < M; i++) {
    bool can = true;
    for (int j = 0; j < N; j++) {
      if (!map[j][i]) {
        can = false;
        continue;
      }
    }
    if (can) res++;
  }
  cout << res;
}
