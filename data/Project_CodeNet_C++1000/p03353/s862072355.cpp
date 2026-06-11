#include <stdio.h>

// char s[5001], t[6], c[5];
// int k, n, l[6], i, j, iM;
int main() {
  int k, n, l[6] = {};
  char s[5001] = {}, t[6] = {}, c[5] = {};
  scanf("%s", s);
  scanf("%d", &k);
  n = 5000;
  int low = 0;
  while (n - low > 1) {
    int mid = (n + low) >> 1;
    (s[mid] ? low : n) = mid;
  }
  for (c[0] = 'a'; c[0] <= 'z'; ++c[0]) {
    t[0] = c[0];
    l[1 + 0] = -1;
    for (int i = l[0], iM = n - 0; i < iM; ++i) {
      if (s[i + 0] != t[0]) continue;
      l[1 + 0] = i;
      break;
    }
    if (l[1] < 0) continue;
    if (k == 1) {
      printf("%s\n", t);
      return 0;
    }
    --k;
    for (c[1] = 'a'; c[1] <= 'z'; ++c[1]) {
      t[1] = c[1];
      l[1 + 1] = -1;
      for (int i = l[1], iM = n - 1; i < iM; ++i) {
        if (s[i + 0] != t[0] || s[i + 1] != t[1]) continue;
        l[1 + 1] = i;
        break;
      }
      if (l[2] < 0) continue;
      if (k == 1) {
        printf("%s\n", t);
        return 0;
      }
      --k;
      for (c[2] = 'a'; c[2] <= 'z'; ++c[2]) {
        t[2] = c[2];
        l[1 + 2] = -1;
        for (int i = l[2], iM = n - 2; i < iM; ++i) {
          if (s[i + 0] != t[0] || s[i + 1] != t[1] || s[i + 2] != t[2]) continue;
          l[1 + 2] = i;
          break;
        }
        if (l[3] < 0) continue;
        if (k == 1) {
          printf("%s\n", t);
          return 0;
        }
        --k;
        for (c[3] = 'a'; c[3] <= 'z'; ++c[3]) {
          t[3] = c[3];
          l[1 + 3] = -1;
          for (int i = l[3], iM = n - 3; i < iM; ++i) {
            if (s[i + 0] != t[0] || s[i + 1] != t[1] || s[i + 2] != t[2] || s[i + 3] != t[3]) continue;
            l[1 + 3] = i;
            break;
          }
          if (l[4] < 0) continue;
          if (k == 1) {
            printf("%s\n", t);
            return 0;
          }
          --k;
          for (c[4] = 'a'; c[4] <= 'z'; ++c[4]) {
            t[4] = c[4];
            l[1 + 4] = -1;
            for (int i = l[4], iM = n - 4; i < iM; ++i) {
              if (s[i + 0] != t[0] || s[i + 1] != t[1] || s[i + 2] != t[2] || s[i + 3] != t[3] || s[i + 4] != t[4]) continue;
              l[1 + 4] = i;
              break;
            }
            if (l[5] < 0) continue;
            if (k == 1) {
              printf("%s\n", t);
              return 0;
            }
            --k;
          }
          t[4] = 0;
        }
        t[3] = 0;
      }
      t[2] = 0;
    }
    t[1] = 0;
  }
}
