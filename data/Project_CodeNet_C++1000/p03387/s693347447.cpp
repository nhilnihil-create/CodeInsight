#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];
  sort(a.rbegin(), a.rend());
  int ans = 0;
  int b, c;
  b = (a[0] - a[1])/2;
  c = (a[0]-a[2])/2;
  ans += b+c;
  a[1] += b*2;
  a[2] += c*2;
  if (a[1] != a[0] && a[2] != a[0]) ans++;
  else if ((a[1] != a[0] && a[2] == a[0]) || (a[1] == a[0] && a[2] != a[0])) ans +=2;
  cout << ans << endl;
  return 0;
}
