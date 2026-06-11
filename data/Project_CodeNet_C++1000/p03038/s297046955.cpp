#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n,m;
int a[100000];

signed main() {
  cin >> n >> m;
  rep(i,n) cin >> a[i];
  map<int ,int> mp;
  rep(i,m) {
    int b,c; cin >> b >> c;
    mp[c] += b;
  }
  //for(auto i = mp.rbegin(); i != mp.rend(); i++) {
  //  auto item = (*i);
  //  cout << item.first << ": " << item.second << endl;
  //}
  sort(a, a+n);
  ll ans = 0;
  rep(i,n) {
    if (!mp.empty()) {
      auto item = *mp.rbegin();
      if (a[i] < item.first) {
        a[i] = item.first;
        if(item.second==1) mp.erase(item.first);
        else mp[item.first]--;
      }
    }
    ans += a[i];
  }
  cout << ans << endl;
}
