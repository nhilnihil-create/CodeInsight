#include <cstdio>

using namespace std;

int table[501][501];

int main() {
  int N, M, Q;
  scanf("%d %d %d", &N, &M, &Q);

  for (int i = 0; i < M; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    table[l][r]++;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      table[i][j] += table[i - 1][j] + table[i][j - 1] - table[i - 1][j - 1];
    }
  }
  for (int i = 0; i < Q; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    const int ans =
        table[q][q] - table[p - 1][q] - table[q][p - 1] + table[p - 1][p - 1];
    printf("%d\n", ans);
  }

  return 0;
}
