#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N;
  cin >> N;

  map<int, int> mp;
  rep(i,0,N-1) {
    int a;
    cin >> a;
    mp[a]++;
  }

  int ans = 0;
  for (auto p : mp) {
    if (p.first <= p.second) ans += p.second - p.first;
    else ans += p.second;
  }

  cout << ans << endl;
  return 0;
}
