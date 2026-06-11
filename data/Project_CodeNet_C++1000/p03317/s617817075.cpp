#include <bits/stdc++.h>

const int N = 1e5 + 10;

int n, k;  
int a[N];

inline int solve(int a, int b) {
  if (a % b == 0) {
    return a / b;
  } else {
    return a / b + 1;   
  }
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);      
  }      
  printf("%d\n", 1 + solve(n - k, k - 1));
  return 0;     
}