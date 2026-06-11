#include <stdio.h>
typedef long long ll;

int main() {
  int k;
  scanf("%d", &k);
  ll a[100005];
  for (int i = 0; i < k; i++) {
    scanf("%lld", &a[i]);
  }
  ll mn = 2;
  ll mx = 2;
  for (int i = k - 1; i >= 0; i--) {
    // [L, R]のaの倍数のminは、ceil(L/a)*a
    //                  maxは、floar(R/a)*a
    if (mn % a[i]) {
      mn += a[i] - mn % a[i];
    }
    mx = mx - mx % a[i] + a[i] - 1;
    if (mn > mx) {
      puts("-1");
      return 0;
    }
  }
  printf("%lld %lld", mn, mx);
}
