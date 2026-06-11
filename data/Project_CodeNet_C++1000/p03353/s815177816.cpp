#include <stdio.h>
#include <string.h>

inline int findstr(const char* s, const int& begin, const int& end, const char* t, const int& tl) {
  for (int i = begin; i <= end - tl;) {
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
  char s[5001] = {};
  int k;
  scanf("%s", s);
  scanf("%d", &k);
  const int n = strlen(s);
  char t[6] = {};
  for (char c = 'a'; c <= 'z'; ++c) {
    t[0] = c;
    int l0 = findstr(s, 0, n, t, 1);
    if (l0 < 0) continue;
    if (k == 1) {
      printf("%s\n", t);
      return 0;
    }
    --k;
    for (char c = 'a'; c <= 'z'; ++c) {
      t[1] = c;
      int l1 = findstr(s, l0, n, t, 2);
      if (l1 < 0) continue;
      if (k == 1) {
        printf("%s\n", t);
        return 0;
      }
      --k;
      for (char c = 'a'; c <= 'z'; ++c) {
        t[2] = c;
        int l2 = findstr(s, l1, n, t, 3);
        if (l2 < 0) continue;
        if (k == 1) {
          printf("%s\n", t);
          return 0;
        }
        --k;
        for (char c = 'a'; c <= 'z'; ++c) {
          t[3] = c;
          int l3 = findstr(s, l2, n, t, 4);
          if (l3 < 0) continue;
          if (k == 1) {
            printf("%s\n", t);
            return 0;
          }
          --k;
          for (char c = 'a'; c <= 'z'; ++c) {
            t[4] = c;
            int l4 = findstr(s, l3, n, t, 5);
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
