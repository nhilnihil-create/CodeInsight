#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int main() {
  int n;
  cin >> n;
  map<ll,int> mp;
  ll ans = 0, sum = 0;
  mp[0]++;
  rep(i,n) {
    int x;
    cin >> x;
    sum += x;
    if(mp[sum]>0) ans += mp[sum];
    mp[sum]++;
  }
  cout << ans << endl;
  return 0;
}