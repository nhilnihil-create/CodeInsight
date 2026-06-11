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
  int x, y, z;
  cin >> x >> y >> z;
  int k;
  cin >> k;
  vector<ll> a(x);
  rep(i, x) cin >> a.at(i);
  vector<ll> b(y);
  rep(i, y) cin >> b.at(i);
  vector<ll> c(z);
  rep(i, z) cin >> c.at(i);
  vector<ll> ab(x*y);
  rep(i, x)rep(j, y){
    ab.at(i*y+j) = a.at(i)+b.at(j);
  }

  sort(ab.rbegin(), ab.rend());
  sort(c.rbegin(), c.rend());
  ab.push_back(-1e18);
  c.push_back(-1e18);
  vector<ll> ans(k);
  vector<int> indexs(z, 0);
  rep(i, k){
    ll mx = -1e18;
    int adi = -1;
    rep(j, z){
      ll add = c.at(j) + ab.at(indexs.at(j));
      if(add > mx){
        mx = add;
        adi = j;
      }
    }
    if(adi == -1) return 1;
    ans.at(i) = mx;
    indexs.at(adi)++;
  }
  for(auto o : ans){
    cout << o << endl;
  }
  return 0;
}