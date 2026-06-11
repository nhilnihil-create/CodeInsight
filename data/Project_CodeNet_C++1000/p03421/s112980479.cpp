#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int p[N];

template <class T>
void read(T &x) {
  char ch = getchar(); x = 0;
  for(; ch < '0' || ch > '9'; ch = getchar()) ;
  for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
}

void fail() {
  puts("-1");
  exit(0);
}

int main() {
  int n, A, B;
  read(n), read(A), read(B);
  int l = (n - 1) / A + 1, r = n - A + 1;
  if(B < l || B > r) fail();  
  int now = n;
  for(int i = B; i >= 1; --i) {
    p[i] = min(A, now - i + 1);
    now -= p[i];
  }
  now = n;
  for(int i = B; i >= 1; --i) {
    for(int j = now - p[i] + 1; j <= now; ++j)
      printf("%d ", j);
    now -= p[i];
  }
  return 0;
}