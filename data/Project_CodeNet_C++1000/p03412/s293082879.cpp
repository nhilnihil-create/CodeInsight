#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

ll a[maxn], b[maxn], c[maxn], d[maxn];
int n;

int process(ll l, ll r) {
  l--;
  ll ret = 0;
  int i = 1, j = n;
  while (i <= n) {
    while (j > 0 && a[i] + b[j] > l) --j;
    ret -= j;
    ++i;
  }
  i = 1; j = n;
  while (i <= n) {
    while (j > 0 && a[i] + b[j] > r) --j;
    ret += j;
    ++i;
  }
  return (ret % 2);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//  freopen("abc.inp", "r", stdin); freopen("abc.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }

  for (int i = 1; i <= n; ++i) {
    cin >> d[i];
  }
  int ans = 0;
  for (int k = 0; k <= 29; ++k) {
    ll T = (1 << k);
    for (int i = 1; i <= n; ++i) {
      a[i] = c[i] % (T<<1);
      b[i] = d[i] % (T<<1);
    }
    sort(a+1, a+n+1); sort(b+1, b+n+1);
    int num = process(T, 2*T-1) + process(3*T, 4*T-1);
    num = num % 2;
    if (num) ans = ans + (1 << k);
  }

  cout << ans;
  return 0;
}
