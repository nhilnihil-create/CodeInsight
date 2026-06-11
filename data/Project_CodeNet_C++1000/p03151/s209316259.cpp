#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int a[100010], b[100010], c[100010]; 
int main() {
  int n;
  cin >> n;
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  ll ans = 0, change = 0;
  vector<int> c;
  rep(i,n) {
    if (a[i] < b[i]) {
      ans++;
      change += b[i] - a[i];
    } else {
      c.push_back(a[i]-b[i]);
    }
  }
  sort(c.begin(), c.end(), greater<int>());
  //int j = 0;
  for (auto v: c) {
    if (change <= 0) break;
    change -= v;
    ans++;
  }
  
  if (change <= 0) cout << ans << endl;
  else cout << -1 << endl;
  return 0;
}