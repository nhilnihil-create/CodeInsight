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
using P = std::pair<char, ll>;
 
#define rep(i, a, b) for (ll(i) = (a); (i) < (b); (i)++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug " << #i <<" "<<i<<std::endl;
 
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

//非再帰累乗(mod付き)
ll pow_mod(ll a, ll b, ll mod=-1) {
  if ((a == 0)||(mod!=-1&&a%mod==0)) {
    return 0;
  }

  ll x = 1;

  while (b > 0) {
    if (b & 1) {
      x = (mod!=-1)?(x * a) % mod:x*a;
    }
    a = (mod!=-1)?(a * a) % mod:a*a;
    b >>= 1;
  }
  return x;
}
 
// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;
 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  ll n;
  std::cin>>n;

  std::vector<ll> lsec(n),rsec(n);

  rep(i,0,n){
    std::cin>>lsec[i]>>rsec[i];
  }

  std::sort(all(rsec));
  std::sort(all(lsec),std::greater<ll>());

  std::vector<ll> rsum(n+1,0),lsum(n+1,0);

  rep(i,0,n){
    rsum[i+1]=rsum[i]+rsec[i];
    lsum[i+1]=lsum[i]+lsec[i];
  }

  ll ans=0;

  rep(r,0,(n+3)/2){
    rep(l,std::max(r-1,0ll),r+2){
      if(r>=0&&l>=0&&r+l<=n){
        chmax(ans,2*lsum[l]-2*rsum[r]);
      }
    }
  }

  std::cout<<ans;

  return 0;
}



