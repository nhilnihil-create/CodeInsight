#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int a[100010], l[100010], r[100010]; 
int main() {
  int n;
  cin >> n;
  rep(i,n) cin >> a[i];
  l[0] = 0;
  rep(i,n) {
    l[i+1] = __gcd(l[i],a[i]);
  }
  r[n+1] = 0;
  irep(i,n) {
    r[i] = __gcd(r[i+1],a[i]);
  }
  int ans = 0;
  for (int i = 0; i <= n; i++)
  {
    int now = __gcd(l[i], r[i+1]);
    ans = max(ans,now);
  }
  cout << ans << endl;
  //rep(i,n+1) cout << r[i] << endl;
  return 0;
}