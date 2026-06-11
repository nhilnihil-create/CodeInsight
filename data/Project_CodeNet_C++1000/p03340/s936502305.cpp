#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) (int)(x).size()

const int N = 200010;
int n, a[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  
  int j = 0, sm = 0, x = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    sm += a[i];
    while ((x ^ a[i]) != sm) {
      x ^= a[j];
      sm -= a[j];
      j++;
    }
    x ^= a[i];
    ans += (i - j + 1);
  }
  printf("%lld\n", ans);
}

