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
  int n, k;
  cin >> n >> k;
  multiset<ll> se;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  rep(i, n){
    ll add = 0;
    rep2(j, i, n){
      add += a.at(j);
      se.insert(add);
    }
  }

  ll ans = 0;
  rrep(bit, 45){
    int co = 0;
    for(auto l : se){
      if((l & (1LL << bit)) != 0) co++;
    }
    if(co >= k){
      auto itr = se.begin();
      while(itr != se.end()){
        if((*itr & (1LL << bit)) == 0){
          itr = se.erase(itr);
        }else{
          itr++;
        }
      }
      // cerr << endl;
      // for(auto i : se){
      //   cerr << i << " ";
      // }
      // cerr << endl;
      ans += 1LL << bit;
    }
    // cerr << co << " " << bit << " " << ans << endl;
  }
  cout << ans << endl;
  return 0;
}