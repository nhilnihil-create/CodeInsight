#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n;
  cin >> n;
  ll a[n];
  rep(i,n) cin >> a[i];
  vector<ll> pt(40,1);
  for(int i = 1; i < 40; i++) pt[i] = pt[i-1] * 2;
  multiset<ll> ms;
  rep(i,n) ms.insert(a[i]);
  sort(a,a+n,greater<ll>());
  int ans = 0;
  rep(i,n) {
    auto itr = ms.find(a[i]);
    if(itr != ms.end()) {
      ms.erase(itr);
      for(int j = 39; j >= 0; j--) {
        ll v = pt[j] - a[i];
        itr = ms.find(v);
        if(itr != ms.end()) {
          ans++;
          ms.erase(itr);
          break;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
