#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 100100; 

int n, a[N], b[N], ans; 
ll num, c[2 * N]; 

int lb(int x) {
  return x & (-x); 
}

void add(int x, int d) {
  for(int i = x; i <= 2 * n + 2; i += lb(i)) {
    c[i] += d; 
  }
}

ll sum(int x) {
  ll ret = 0;
  for(int i = x; i; i -= lb(i))
    ret += c[i]; 
  return ret; 
}

bool check(int x) {
  memset(c, 0, sizeof(c)); 
  for(int i = 1; i <= n; i++) {
    b[i] = a[i] >= x ? 1 : -1;
    b[i] += b[i - 1];  
  }
  for(int i = 1; i <= n; i++) b[i] += n + 1; 
  ll t = 0; 
  add(n + 1, 1);
  for(int i = 1; i <= n; i++) {
    t += sum(b[i]); 
    add(b[i], 1); 
  }
    return t >= num - (num / 2 + 1) + 1; 
}

int main() {
  scanf("%d", &n); 
  for(int i = 1; i <= n; i++) 
    scanf("%d", &a[i]); 
  num = 1ll * n * (n + 1) / 2; 
  int l = 1, r = (int)1e9; 
  while(l <= r) {
    int mid = (l + r) >> 1; 
    if(check(mid)) {
      ans = mid; l = mid + 1; 
    }
    else r = mid - 1; 
  }
  printf("%d\n", ans); 
  return 0; 
}