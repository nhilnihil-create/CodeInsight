#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  map<int, ll> mp;
  rep(i, n){
    int a;
    cin >> a;
    mp[a]++;
  }
  rep(i, m){
    int b, c;
    cin >> b >> c;
    mp[c] += b;
  }

  ll ans = 0;
  rrepit(itr, mp){
    if(n - itr->second <= 0){
      ans += (ll)itr->first * n;
      break;
    }else{
      ans += (ll)itr->first * (itr->second);
      n -= itr->second;
    }
  }
  cout << ans << endl;
  return 0;
}