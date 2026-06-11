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
#define debug(i) std::cerr << "debug "<< i << std::endl

// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

ll gcd(ll x,ll y){
  if(x%y==0)return y;
  else return gcd(y,x%y);
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll t;
  std::cin>>t;

  rep(i,0,t){
    ll a,b,c,d;
    std::cin>>a>>b>>c>>d;

    if(b>a){
      std::cout<<"No\n";
      continue;
    }else if(b>d){
      std::cout<<"No\n";
      continue;
    }else if(c>=b){
      std::cout<<"Yes\n";
      continue;
    }

    ll g=gcd(b,d);
    if(b+(a%g)-g>c)std::cout<<"No\n";
    else std::cout<<"Yes\n";
  }

  return 0;
}
