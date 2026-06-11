#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  
  map<int, int> mp;
  rep(i, n) ++mp[a[i]];
  int ans = 0;
  for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
    int f = (*itr).first;
    int s = (*itr).second;
    if (s >= f) ans += s - f;
    else ans += s; 
  }
  cout << ans << endl;
  return 0;
}