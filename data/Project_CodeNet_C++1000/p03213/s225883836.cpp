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

map<ll, ll> prime_factorization(ll n){
  map<ll, ll> ans;
  ll a = 2;
  while(n >= a*a){
    if(n % a == 0){
      ans[a]++;
      n /= a;
    }else{
      a++;
    }
  }
  ans[n]++;

  return ans;
}

int main(){
  int n;
  cin >> n;
  map<ll, ll> pt;
  rep2(i, 1, n+1){
    auto add = prime_factorization(i);
    for(auto p : add){
      pt[p.first] += p.second;
    }
  }

  repit(itr, pt){
    cerr << itr->first << " " << itr->second << endl;
  }

  int c74 = 0, c24 = 0, c14 = 0, c4 = 0, c2 = 0;
  for(auto p : pt){
    if(p.second >= 74) c74++;
    if(p.second >= 24) c24++;
    if(p.second >= 14) c14++;
    if(p.second >= 4) c4++;
    if(p.second >= 2) c2++;
  }
  cerr << c74 << " " << c24 << " " << c14 << " " << c4 << " " << c2 << endl;
  ll ans = c74;
  ans += (ll)c24 * (c2 - 1);
  ans += (ll)c14 * (c4 - 1);
  cerr << ans << endl;
  ans += (ll)c4 * (c4-1)/2 * (c2-2);
  cout << ans << endl;
  return 0;
}