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
using P = std::pair<long double, ll>;
 
#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug " << #i <<" "<<i<< std::endl
 
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
 
// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;
 

 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  ll n,k,q;
  std::cin>>n>>k>>q;

  std::vector<ll> a(n);
  rep(i,0,n)std::cin>>a[i];

  ll ans=LLONG_MAX;

  rep(i,0,n){
    ll min=a[i];

    ll cnt=0;
    std::vector<ll> temp;
    rep(j,0,n){
      if(a[j]<min){
        if(cnt>=k){
          std::vector<ll> temp2;
          rep(l,j-cnt,j){
            temp2.push_back(a[l]);
          }
          std::sort(all(temp2));
          rep(l,0,cnt-k+1)temp.push_back(temp2[l]);
        }
        cnt=0;
      }else{
        cnt++;
      }
    }
    if(cnt>=k){
      std::vector<ll> temp2;
      rep(l,n-cnt,n)temp2.push_back(a[l]);
      std::sort(all(temp2));
      rep(l,0,cnt-k+1)temp.push_back(temp2[l]);
    }

    std::sort(all(temp));

    ll max;
    if(temp.size()<q)max=LLONG_MAX;
    else max=temp[q-1];

    chmin(ans,max-min);
  }

  std::cout<<ans;

  return 0;
}



