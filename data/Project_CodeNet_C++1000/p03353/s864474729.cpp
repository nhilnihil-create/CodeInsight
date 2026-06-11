#include <stdio.h>
#include <string.h>

char s[5001], t[6], c[5];
int k, n;
inline int findstr(const int& begin, const int& tl) {
  for (int i = begin; i <= n - tl;) {
    for (int j = 0; j < tl; ++j) {
      if (s[i + j] != t[j]) goto cont;
    }
    return i;
  cont:
    ++i;
  }
  return -1;
}
int main() {
  scanf("%s", s);
  scanf("%d", &k);
  n = strlen(s);
  for (c[0] = 'a'; c[0] <= 'z'; ++c[0]) {
    t[0] = c[0];
    int l0 = findstr(0, 1);
    if (l0 < 0) continue;
    if (k == 1) {
      printf("%s\n", t);
      return 0;
    }
    --k;
    for (c[1] = 'a'; c[1] <= 'z'; ++c[1]) {
      t[1] = c[1];
      int l1 = findstr(l0, 2);
      if (l1 < 0) continue;
      if (k == 1) {
        printf("%s\n", t);
        return 0;
      }
      --k;
      for (c[2] = 'a'; c[2] <= 'z'; ++c[2]) {
        t[2] = c[2];
        int l2 = findstr(l1, 3);
        if (l2 < 0) continue;
        if (k == 1) {
          printf("%s\n", t);
          return 0;
        }
        --k;
        for (c[3] = 'a'; c[3] <= 'z'; ++c[3]) {
          t[3] = c[3];
          int l3 = findstr(l2, 4);
          if (l3 < 0) continue;
          if (k == 1) {
            printf("%s\n", t);
            return 0;
          }
          --k;
          for (c[4] = 'a'; c[4] <= 'z'; ++c[4]) {
            t[4] = c[4];
            int l4 = findstr(l3, 5);
            if (l4 < 0) continue;
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
