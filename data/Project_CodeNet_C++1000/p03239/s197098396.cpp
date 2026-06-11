#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, t;
  cin >> n >> t;
  vector<pair<int, int>> v(n);
  for(int i=0; i<n; i++) {
    int a, b;
    cin >> a >> b;
    v[i] = make_pair(a, b);
  }
  
  int ans = 1001;
  for(auto x : v) {
    int a, b;
    tie(a, b) = x;
    if(b <= t && a < ans) {
      ans = a;
    }
  }
  if(ans != 1001) cout << ans << endl;
  else cout << "TLE" << endl;
  return 0;
}