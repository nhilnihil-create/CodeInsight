#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  rep(i,n)
  {
    scanf("%d", &a[i]);
    a[i] -= i + 1;
  }
  sort(a.begin(), a.end());
  int b = a[n / 2];
  long long ans = 0;
  rep(i,n)
    ans += abs(b - a[i]);
  printf("%lld", ans);
  return 0;
}
