#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) (int)(x).size()

const int N = 510;
const int M = 35;
int n, c;
int freq[3][M], d[M][M], best;

int main() {
  scanf("%d%d", &n, &c);
  memset(d, 0, sizeof d);
  memset(freq, 0, sizeof freq);

  for (int i = 1; i <= c; i++)
    for (int j = 1; j <= c; j++)
      scanf("%d", &d[i][j]);
      
  int col;
  for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
    scanf("%d", &col);
    freq[(i + j) % 3][col]++;
  }

  best = 2e9;
  for (int i = 1; i <= c; i++) {
    for (int j = 1; j <= c; j++) {
      for (int k = 1; k <= c; k++) {
        if (i == j || i == k || j == k) continue;
        int tmp = 0;
        for (int t = 1; t <= c; t++) {
          tmp += freq[0][t] * d[t][i];
          tmp += freq[1][t] * d[t][j];
          tmp += freq[2][t] * d[t][k];
        }
        best = min(best, tmp);
      }
    }
  }
  printf("%d\n", best);
}

