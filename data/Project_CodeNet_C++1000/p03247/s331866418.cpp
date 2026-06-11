#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000 + 7;

int X[MAX_N], Y[MAX_N];

int main() {
  int N, c = 0;

  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d%d", &X[i], &Y[i]);

    if ((X[i] + Y[i]) & 1) c++;
    else c--;
  }

  if (abs(c) != N) {
    puts("-1");
    return 0;
  }

  int m = 31 + (c < 0);
  printf("%d\n", m);
  for (int i = 0; i < 31; i++)
    printf("%d ", (1 << i));
  if (c < 0) printf("1\n");
  else printf("\n");

  for (int i = 1; i <= N; i++) {
    int x = X[i];
    int y = Y[i];
    char ans[32 + 7] = {0};

    if (c < 0) {
      ans[31] = 'R';
      x--;
    }

    bool flag = 0;
    for (int j = 30; j >= 0; j--) {
      if (abs(x) < abs(y)) {
        swap(x, y);
        flag ^= 1;
      }

      if (x > 0) {
        x -= (1 << j);
        ans[j] = flag ? 'U' : 'R';
      }
      else {
        x += (1 << j);
        ans[j] = flag ? 'D' : 'L';
      }
    }

    puts(ans);
  }

  return 0;
}
