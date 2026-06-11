#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vll vector<ll>
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
typedef long long int ll;
typedef long double ld;
using namespace std;

struct Merge{
  set<vll> lr;
  ll INF = 1000000000000000009;
  vll remove(ll a, ll b){
    if(a>b) swap(a, b);
    auto itr = lr.lower_bound(vll{b+1, 0});
    if(itr==lr.begin()) return vll{a, b};
    itr--;
    ll lef = a, ri = b;
    while((*itr)[1]>=a){
      ll now_x = (*itr)[0], now_y = (*itr)[1];
      lef = min(lef, now_x), ri = max(ri, now_y);
      if(itr==lr.begin()){
        lr.erase(itr);
        break;
      }
      itr--;
      lr.erase(vll{now_x, now_y});
    }
    return vll{lef, ri};
  }
  void merge(ll a, ll b){lr.insert(remove(a, b));}
  vll get(ll a){
    auto itr = lr.lower_bound(vll{a+1, 0});
    if(itr==lr.begin()) return vll{INF, INF};
    itr--;
    if((*itr)[1]<a) return vll{INF, INF};
    return *itr;
  }
  bool same(ll a, ll b){
    if(get(a)[0]==-1) return false;
    return get(a)[0]==get(b)[0];
  }
};
int main(int argc, char const *argv[]) {
  ll x, y, z, n, c;std::cin >> n >> c;
  vector<Merge> mg(c+1);
  re(i, n){
    std::cin >> x >> y >> z;
    mg[z].merge(x, y);
  }
  multimap<ld, ll> mp;
  re(i, c+1){
    for(auto itr = mg[i].lr.begin();itr!=mg[i].lr.end();itr++){
      mp.emplace((ld)(*itr)[0] - 0.5, 1);
      mp.emplace((*itr)[1], -1);
    }
  }
  ll now = 0;
  ll ans = 0;
  for(auto itr = mp.begin();itr!=mp.end();itr++){
    if((*itr).second==1) now++;
    else now--;
    ans = max(ans, now);
    //std::cout << (*itr).first << " " << (*itr).second << '\n';
  }
  std::cout << ans << '\n';
  return 0;
}
