#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int n;
ll a[N], sum[N];
map<ll, int> s;

int main() {
  scanf("%d", &n);
  ll ans = 0;
  s[0]++;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    sum[i] = sum[i - 1] + a[i];
    ans += s[sum[i]];
    s[sum[i]]++;
  }
  printf("%lld\n", ans);
  return 0; 
}