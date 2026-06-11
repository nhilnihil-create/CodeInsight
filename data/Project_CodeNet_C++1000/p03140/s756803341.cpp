#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  string a, b, c;
  cin >> n >> a >> b >> c;
  int ans = 0;
  rep(i, n) {
    if (a[i] == b[i] && a[i] == c[i]) continue;
    if (a[i] != b[i] && b[i] != c[i] && c[i] != a[i]) ans++;
    ans++;
  }
  cout << ans << endl;
  return 0;
}