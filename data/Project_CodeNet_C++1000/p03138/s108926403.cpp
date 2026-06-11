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

ll fc(vector<bool> &ax, int index, ll x, vector<ll> &a){
  rep(i, index){
    if(ax.at(i) == true) x += 1LL << i;
  }
  ll res = 0;
  rep(i, a.size()){
    res += a.at(i) ^ x;
  }
  return res;
}

int main(){
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  vector<bool> ax(50);
  rep(i, 50){
    int c0 = 0, c1 = 0;
    rep(j, n){
      if((a.at(j) & (1LL << i)) == 0) c0++;
      else c1++;
    }
    if(c0 > c1) ax.at(i) = true;
    else ax.at(i) = false;
  }
  ll x = 0, ans = 0;
  rrep(i, 50){
    if((k & (1LL << i)) == 0){
    }else{
      ans = max(ans, fc(ax, i, x, a));
      x += 1LL << i;
    }
    if(i == 0) ans = max(ans, fc(ax, i, x, a));
  }
  cout << ans << endl;
  return 0;
}