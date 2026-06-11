#include <assert.h>
#include <limits.h>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <complex>
#include <deque>
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
#define debug(i) std::cout << i << "\n"

//const ll MOD = 998244353;
const ll MOD = 1e9+7;
 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n,sum=0,min=LLONG_MAX;
  std::cin>>n;
  bool isSame=true;
  rep(i,0,n){
    ll a,b;
    std::cin>>a>>b;
    sum+=a;
    if(a!=b){
      isSame=false;
      if(a>b){
        min=std::min(min,b);
      }
    }
  }

  if(isSame)std::cout<<0;
  else std::cout<<sum-min;

  return 0;
}