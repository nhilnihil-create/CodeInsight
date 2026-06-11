#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10, LOG = 28;
int n;
int a[N], b[N], A[N], B[N];

int find(int x, int y) {
  int l = 1, r = n, ans = 0;
  while(l <= r) {
    int mid = (l + r) >> 1;
    if(B[mid] + x <= y) ans = mid, l = mid + 1;
    else r = mid - 1;
  }
  return ans;  
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for(int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  int ans = 0;
  for(int i = 0; i <= LOG; ++i) {
    int base = (1 << (i + 1)) - 1;
    for(int j = 1; j <= n; ++j) A[j] = a[j] & base;
    for(int j = 1; j <= n; ++j) B[j] = b[j] & base;
    sort(B + 1, B + 1 + n);
    ll pos = 1ll * n * n;
/*    for(int j = 1; j <= n; ++j) 
      printf("%d ", A[j]);
    puts("");
    for(int j = 1; j <= n; ++j)
      printf("%d ", B[j]);
    puts("");*/
    for(int j = 1; j <= n; ++j) {
      pos -= find(A[j], (1 << i) - 1);
      pos -= find(A[j], (1 << (i + 1)) + (1 << i) - 1) - find(A[j], (1 << (i + 1)) - 1);
    }
//    printf("%lld\n", pos);
    if(pos & 1) ans |= (1 << i);
  }
  printf("%d\n", ans);
  return 0;
}