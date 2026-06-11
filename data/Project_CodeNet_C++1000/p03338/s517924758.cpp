#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<char> a(n);
  rep(i,n) cin >> a[i];
  int ans = 0;
  rep(i,n) {
    set<char> b;
    int cnt = 0;
    rep(j,i) b.insert(a[j]);
    for(int k = n-1; k >= i; k--) {
      if(b.count(a[k])) cnt++;
      b.erase(a[k]);
    }
    ans = max(ans,cnt);
  }
  cout << ans << endl;
  return 0;
}