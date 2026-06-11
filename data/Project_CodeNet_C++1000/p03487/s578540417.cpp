#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  map<int, int> mp;
  rep(i,n) mp[a[i]]++;

  int ans = 0;
  for (auto p : mp) {
    int x = p.first;
    int n = p.second;
    if (n > x) ans += n-x;
    else if (n < x) ans += n;
  }
  cout << ans << endl;
  return 0;
}