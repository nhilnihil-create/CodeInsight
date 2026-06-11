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

const ll INF = 1e18;

int main(){
  ll d, g;
  cin >> d >> g;
  vector<ll> p(d), c(d);
  rep(i, d){
    ll a, b;
    cin >> a >> b;
    p.at(i) = a; c.at(i) = b;
  }
  
  ll ans = INF;
  rep(bit, 1 << d){
    ll add = 0;
    ll sum = 0;
    rep(i, d){
      if((bit & (1 << i)) != 0){
        add += p.at(i);
        sum += 100*p.at(i)*(i+1)+c.at(i);
      }
    }
    if(sum >= g){
      ans = min(ans, add);
      continue;
    }

    rrep(i, d){
      if((bit & (1 << i)) != 0) continue;
      if(sum + 100*p.at(i)*(i+1) >= g){
        add += (g-sum+((100*(i+1)-1)))/(100*(i+1));
        ans = min(ans, add);
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}