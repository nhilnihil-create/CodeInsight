#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  vector<int> a(3);
  rep(i,3) cin >> a[i];

  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());

  int ans = 0;
  int diff = a[0] - a[1];
  diff /= 2;
  ans += diff;
  a[1] += diff*2;
  diff = a[0] - a[2];
  diff /= 2;
  ans += diff;
  a[2] += diff*2;
  if (a[0] != a[1] && a[0] != a[2]) {
    ans++;
  } else if (a[0]==a[1] && a[0]==a[2]) {
    ans += 0;
  } else {
    ans += 2;
  }
  
  cout << ans << endl;
  return 0;
}