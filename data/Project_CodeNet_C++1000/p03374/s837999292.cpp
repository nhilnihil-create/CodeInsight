#include <bits/stdc++.h>

using namespace std;


#define MAXN 100001
typedef long long ll;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, c, x[MAXN], v[MAXN];
  cin >> n >> c;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> v[i];
  }
  ll ans = 0, pos = 0, cur = 0;
  ll mxr[MAXN] = {};
  ll mxl[MAXN] = {};
  for (int i = 0; i < n; ++i) {
    cur += v[i]-(x[i]-pos);
    pos = x[i];
    mxr[i] = max(i ? mxr[i-1] : (ll)-1e18, cur);
    ans = max(ans, cur);
  }
  cur = 0;
  pos = c;
  for (int i = n-1; i >= 0; --i) {
    cur += v[i]-(pos-x[i]);
    pos = x[i];
    mxl[n-i-1] = max(n-i-2>=0 ? mxl[n-i-2] : (ll)-1e18, cur);
    ans = max(ans, cur);
  }
  cur = 0;
  pos = 0;
  for (int i = 0; i < n; ++i) {
    cur += v[i]-2*(x[i]-pos);
    pos = x[i];
    ans = max(ans, cur+((n-i-2>=0) ? mxl[n-i-2] : 0));
  }
  cur = 0;
  pos = c;
  for (int i = n-1; i >= 0; --i) {
    cur += v[i]-2*(pos-x[i]);
    pos = x[i];
    ans = max(ans, cur+((i-1>=0) ? mxr[i-1] : 0));
  }
  cout << ans << endl;
  return 0;
}
