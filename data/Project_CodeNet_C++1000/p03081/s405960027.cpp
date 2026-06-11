#include <stdio.h>

const int N = 2e5 + 10;
char a[N];
char t[N], dir[N];
int n, qq;

bool can_left(int x) {
  int cur = x;
  for (int i = 0; i < qq; i++) {
    if (t[i] == a[cur]) {
      if (dir[i] == 'L') {
        cur--;
      } else {
        cur++;
      }
      if (cur == -1) {
        return true;
      }
    }
  }
  return false;
}

bool can_right(int x) {
  int cur = x;
  for (int i = 0; i < qq; i++) {
    if (t[i] == a[cur]) {
      if (dir[i] == 'L') {
        cur--;
      } else {
        cur++;
      }
      if (cur == n) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  scanf("%d %d", &n, &qq);
  scanf("%s", a);
  for (int i = 0; i < qq; i++) {
    scanf(" %c %c", &t[i], &dir[i]);
  }
  int lo = -1, hi = n;
  int ans = n;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (can_left(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  ans -= lo + 1;
  lo = -1;
  hi = n;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (can_right(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  ans -= n - hi;
  printf("%d\n", ans);
  return 0;
}