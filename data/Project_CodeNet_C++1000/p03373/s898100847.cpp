#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  scanf("%d%d%d%d%d", &A, &B, &C, &X, &Y);

  int A_NUM = 0;
  int B_NUM = 0;
  int ans = 0;
  if (A + B > 2 * C) {
    if (X > Y) {
      ans += 2 * C * Y;
      A_NUM += Y;
      B_NUM += Y;
      if (A_NUM >= X) {
        printf("%d", ans);
        return 0;
      }
    } else if (X == Y) {
      ans += 2 * C * X;
      printf("%d", ans);
      return 0;
    } else if (X < Y) {
      ans += 2 * C * X;
      A_NUM += X;
      B_NUM += X;
      if (B_NUM >= Y) {
        printf("%d", ans);
        return 0;
      }
    }
  }

  if (A > 2 * C) {
    ans += 2 * C * (X - A_NUM);
  } else {
    ans += A * (X - A_NUM);
  }
  if (B > 2 * C) {
    ans += 2 * C * (Y - B_NUM);
  } else {
    ans += B * (Y - B_NUM);
  }

  printf("%d", ans);
  return 0;
}