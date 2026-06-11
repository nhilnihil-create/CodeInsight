#include <assert.h>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << i << "\n"

// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n;
  std::cin>>n;

  std::vector<ll> a(n),value,count;
  rep(i,0,n)std::cin>>a[i];

  std::sort(all(a));

  ll prev=a[0],cnt=1;

  value.push_back(a[0]);

  rep(i,1,n){
    if(a[i]!=prev){
      value.push_back(a[i]);
      count.push_back(cnt);
      cnt=1;
      prev=a[i];
    }else{
      cnt++;
    }
  }

  count.push_back(cnt);

  ll size=value.size(),ans=0;

  for(ll i=size-1;i>=0;i--){
    ll pow=1;
    while(value[i]>=pow)pow*=2;

    ll itr=std::lower_bound(all(value),pow-value[i])-value.begin();

    while(count[i]>0){
      count[i]--;
      if((value[itr]==pow-value[i])&&count[itr]>0){
        ans++;
        count[itr]--;
      }
    }
  }

  std::cout<<ans;

  return 0;
}
