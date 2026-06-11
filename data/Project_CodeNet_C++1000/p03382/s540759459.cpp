#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + 1 + n);
  int be = a[n], pos = a[n] / 2, tmp = a[n] / 2;
  if(a[n] & 1) tmp = pos + 1;
  int ans = 1e9, ed = 0;
  for(int i = 1; i <= n; ++i) {
    int now = 0;
    if(a[i] >= pos) now = a[i] - pos;
    else now = tmp - a[i];
    if(ans > now) ans = now, ed = a[i];
  }
  printf("%d %d\n", be, ed);
  return 0;
}

/*
5
6 9 4 2 11

11 6
*/