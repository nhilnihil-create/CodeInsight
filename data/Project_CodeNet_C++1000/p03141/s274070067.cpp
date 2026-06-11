//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<numeric>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<list>
using namespace std;

typedef long long ll;

#define MOD 1000000007

class Comb{
private:
  ll *fac,*finv,*inv;
public:
  Comb(){
    fac = new ll[1000000];
    finv = new ll[1000000];
    inv = new ll[1000000];
    fac[0] = 1;
    for(int i=1;i<1000000;i++){
      fac[i] = i*fac[i-1];
      fac[i] %= MOD;
    }
    inv[1] = 1;
    for(int i=2;i<1000000;i++){
      inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
    }
    finv[0] = 1;
    for(int i=1;i<1000000;i++){
      finv[i] = inv[i]*finv[i-1];
      finv[i] %= MOD;
    }
  }
  ll calc(ll n,ll k){
    ll c = fac[n];
    c *= finv[k];c %= MOD;
    c *= finv[n-k];c %= MOD;
    return c;
  }
};

ll gcd(ll a,ll b){
  if(a%b == 0) return b;
  else return gcd(b,a%b);
}

int main(){
  int n;
  cin >> n;
  ll a[n],b[n];
  pair<ll,ll> ab[n];
  for(int i=0;i<n;i++){
    cin >> a[i] >> b[i];
    ab[i] = make_pair(a[i]+b[i],i);
  }
  sort(ab,ab+n);
  reverse(ab,ab+n);
  ll ans[2];
  ans[0] = 0;
  ans[1] = 0;
  for(int i=0;i<n;i++){
    if(i%2 == 0){
      ans[0] += a[ab[i].second];
    }
    else{
      ans[1] += b[ab[i].second];
    }
  }
  cout << ans[0] - ans[1] << endl;
  return 0;
}
