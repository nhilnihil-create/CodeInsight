#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  map<int,int> mp;
  rep(i,n) {
    int x;
    cin >> x;
    mp[x]++;
  }
  int ans = 0;
  for(auto p: mp) {
    if(p.second<p.first) ans += p.second;
    else ans += p.second-p.first;
  }

  cout << ans << endl;
}
