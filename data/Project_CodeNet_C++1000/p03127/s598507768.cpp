#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main () {
  int n;
  cin >> n;
  vector<int> a(n);
  
  rep(i, n) cin >> a[i];
  int ans = a[0];

  rep(i, n) ans = __gcd(ans, a[i]);
  cout << ans << endl;
}
  
