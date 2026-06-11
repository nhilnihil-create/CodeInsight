#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  int a[50];
  
  int max_abs_pos = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (i && abs(a[i]) > abs(a[max_abs_pos])) {
      max_abs_pos = i;
    }
  }
  
  printf("%d\n", 2 * (n - 1));
  for (int i = 0; i < n; i++) {
    if (i != max_abs_pos) printf("%d %d\n", max_abs_pos + 1, i + 1);
  }
  
  for (int i = 0; i < n - 1; i++) {
    if (a[max_abs_pos] >= 0) {
      printf("%d %d\n", i + 1, i + 2);
    }
    else {
      printf("%d %d\n", n - i, n - i - 1);
    }
  }
  
  return 0;
}