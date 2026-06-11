#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
  }
  int mn = 2e9;
  ll sum = 0;
  for(int i = 1; i <= n; ++i) {
    sum += b[i];
    if(a[i] > b[i]) mn = min(mn, b[i]);
  }
  if(mn == 2e9) printf("0\n");
  else printf("%lld\n", sum - mn);
  return 0;
}