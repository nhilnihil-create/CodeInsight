#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  vector<int> d(n);
  rep(i, n) d[i] = a[i] - b[i];
  sort(d.begin(), d.end());
  int ci = 0;
  ll qi = 0;
  rep(i, n) if (d[i] < 0) {
    ++ci;
    qi += -d[i];
  }
  int cd = 0;
  ll qd = 0;
  reverse(d.begin(), d.end());
  rep(i, n) {
    if (qd >= qi) break;
    qd += d[i];
    ++cd;
  }
  int ans = -1;
  if (qd >= qi) ans = ci + cd;
  cout << ans << endl; 
  return 0;
}