#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
  int n;
  cin >> n;
  vector<double> a(n);
  rep(i,n) cin >> a[i];
  double s = 0;
  rep(i,n) s += a[i];
  s = s / n;
  int ans = 0;
  rep(i,n) {
    if (abs(s - a[ans]) > abs(s - a[i]) + 0.0005) {
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}