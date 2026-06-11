#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x%y);
}

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  rep(i,n) cin >> a[i];

  //sort(a.begin(),a.end());
  vector<int> l(n);
  rep(i,n-1) l[i+1] = gcd(l[i], a[i]);

  reverse(a.begin(),a.end());
  vector<int> r(n);
  rep(i,n-1) r[i+1] = gcd(r[i], a[i]);
  reverse(r.begin(), r.end());

  int ans = 0;
  rep(i,n) ans = max(ans,gcd(l[i], r[i]));

  cout << ans << endl;

}