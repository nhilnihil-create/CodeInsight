#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int N, M;
  int S[11][11] = {0};
  int C[11] = {0};
  std::cin >> N >> M;

  for (int i = 0; i < M; i++) {
    std::cin >> C[i];
    for (int j = 0; j < C[i]; j++) {
      int s;
      std::cin >> s;
      S[i][j] = (s - 1);
    }
  }

  int P[11];
  for (int i = 0; i < M; i++) {
    std::cin >> P[i];
  }

  int ans = 0;
  for (int bit = 0; bit < (1 << N); bit++) {
    int on_count = 0;
    for (int i = 0; i < M; i++) {
      int c = C[i];
      int on = 0;
      for (int j = 0; j < c; j++) {
        if (bit & (1 << S[i][j])) {
          on++;
        }
      }
      if (on % 2 == P[i]) {
        on_count++;
      }
    }
    if (on_count == M) {
      ans++;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
