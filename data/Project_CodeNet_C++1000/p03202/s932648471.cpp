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
#include <unordered_map>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << "[" << pa.first << ", " << pa.second << "]";
}

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  os << "{";
  for (int i = 0; i < vec.size(); i++)
    os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
  os << "}";
  return os;
}

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug " << i << std::endl

// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  ll n;
  std::cin>>n;

  std::vector<ll> a(n);
  bool flag=true;
  rep(i,0,n)std::cin>>a[i];

  rep(i,1,n)if(a[i-1]>=a[i])flag=false;
  if(flag){
    std::cout<<1;
    return 0;
  }

  ll left=1,right=n+1;

  while(right-left>1){
    ll mid=(left+right)/2;

    std::map<ll,ll> chara;

    bool isok=true;
    ll len=0;
    rep(i,0,n){
      if(a[i]>len){
        len=a[i];
      }else{
        while((!chara.empty())&&chara.rbegin()->first>=a[i]){
          ll val=chara.rbegin()->first;
          chara.erase(val);
        }
        chara[a[i]-1]++;
        ll now=a[i]-1;
        while(chara[now]>=mid){
          chara.erase(now);
          now--;
          chara[now]++;
          if(now<0)isok=false;
        }
        if(!isok)break;
        len=a[i];
      }
    }
    if(isok)right=mid;
    else left=mid;
  }

  std::cout<<right;

  return 0;
}