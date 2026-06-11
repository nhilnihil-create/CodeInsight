#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
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
  map<ll, ll> pm;
  rep2(i, 1, n+1){
    auto add = prime_factorization(i);
    for(auto p : add){
      pm[p.first] += p.second;
    }
  }
  // for(auto p : pm){
  //   cerr << p.first << " " << p.second << endl;
  // }
  int ans = 0;
  for(auto aitr = pm.begin(); aitr != pm.end(); aitr++){
    int ac = aitr->second;
    if(ac >= 74) ans++;
    auto bitr = aitr;
    bitr++;
    for(; bitr != pm.end(); bitr++){
      int bc = bitr->second;
      if(ac >= 14 && bc >= 4) ans++;
      if(ac >= 4 && bc >= 14) ans++;
      if(ac >= 24 && bc >= 2) ans++;
      if(ac >= 2 && bc >= 24) ans++;
      auto citr = bitr;
      citr++;
      for(; citr != pm.end(); citr++){
        int cc = citr->second;
        if(ac >= 2 && bc >= 4 && cc >= 4) ans++;
        if(bc >= 2 && ac >= 4 && cc >= 4) ans++;
        if(cc >= 2 && ac >= 4 && bc >= 4) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}