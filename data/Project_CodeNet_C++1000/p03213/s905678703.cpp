#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
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
  map<ll, ll> pr;
  rep2(i, 2, n+1){
    auto m = prime_factorization(i);
    for(auto p : m){
      pr[p.first] += p.second;
    }
  }
  // for(auto p : pr){
  //   cerr << p.first << " " << p.second << endl;
  // }
  vector<int> pn(5, 0);
  for(auto p : pr){
    if(p.second >= 74) pn.at(4)++;
    else if(p.second >= 24) pn.at(3)++;
    else if(p.second >= 14) pn.at(2)++;
    else if(p.second >= 4) pn.at(1)++;
    else if(p.second >= 2) pn.at(0)++;
  }
  rrep(i, 4) pn.at(i) += pn.at(i+1);
  // rep(i, 4) cerr << pn.at(i) << " ";
  // cerr << endl;
  int ans = 0;
  ans += pn.at(1) * (pn.at(1)-1) * (pn.at(0)-2)/2;
  ans += pn.at(3) * (pn.at(0) - 1);
  ans += pn.at(2) * (pn.at(1) - 1);
  ans += pn.at(4);
  cout << ans << endl;
  return 0;
}