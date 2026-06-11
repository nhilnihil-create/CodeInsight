#include <cassert>
#include "limits.h"
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
#include <random>
#include <memory>
#include <utility>
 
#define rep(i, a, b) for (long long (i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug " <<"LINE:"<<__LINE__<<"  "<< #i <<":"<< i << std::endl

 
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << pa.first << " " << pa.second;
}
 
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (int i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}
 
template<typename T1,typename T2>
inline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}
 
template<typename T1,typename T2>
inline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}
 
long long pow_mod(long long a, long long b, long long mod=-1) {
  if ((a == 0)||(mod!=-1&&a%mod==0)) {
    return 0;
  }
 
  long long x = 1;
 
  while (b > 0) {
    if (b & 1) {
      x = (mod!=-1)?(x * a) % mod:x*a;
    }
    a = (mod!=-1)?(a * a) % mod:a*a;
    b >>= 1;
  }
  return x;
}
 
// const long long MOD = 998244353;
const long long MOD = 1e9 + 7;

using ll = long long;
using P = std::pair<ll, ll>;



int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string s;
  std::cin>>s;

  ll n=s.size();

  std::vector<ll> a(n+1,0);

  rep(i,1,n+1){
    if((a[i-1]>>(s[i-1]-'a'))&1)a[i]=a[i-1]-(1ll<<(s[i-1]-'a'));
    else a[i]=a[i-1]+(1ll<<(s[i-1]-'a'));
  }

  std::vector<int> min(1ll<<26,MOD);

  min[0]=0;

  ll dp=0;

  rep(i,1,n+1){
    ll temp=min[a[i]];

    rep(j,0,26)chmin(temp,min[a[i]^(1ll<<j)]);
    dp=temp+1;
    chmin(min[a[i]],dp);
  }

  std::cout<<dp<<"\n";

  return 0;
}