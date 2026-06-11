#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> d(101);
  int m;
  rep(i,n) {cin >> m; d.at(m) = 1;}
  int ans = 0;
  rep(i,101) ans += d.at(i);
  cout << ans << endl;
}