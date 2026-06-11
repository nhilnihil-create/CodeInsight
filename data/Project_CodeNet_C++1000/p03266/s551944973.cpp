#include <bits/stdc++.h>
 
int n, m, i, j, k;
typedef long long ll;
 
ll ans; 
 
inline ll qp3(ll a) {
  return 1ll * a * a * a;  
}
 
int main() {
  scanf("%d %d", &n, &k);
  int x = n / k;  
  ans = qp3(x);
  if (!(k & 1)) {
    x += (n % k) >= (k / 2);  
    ans += qp3(x);
  }
  printf("%lld\n", ans);
  return 0;       
}