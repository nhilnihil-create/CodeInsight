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
 
#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
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
 
// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;
 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  ll n,q;
  std::cin>>n>>q;

  std::string s;
  std::cin>>s;

  std::vector<P> query(q);
  rep(i,0,q){
    char t,d;
    std::cin>>t>>d;
    ll temp;
    if(d=='L')temp=-1;
    else temp=1;

    query[i]={t,temp};
  }

  ll left=-1,right=n;

  while(right-left>1){
    ll mid=left+(right-left)/2;

    ll now=mid;
    bool isok=true;

    rep(i,0,q){
      if(s[now]==query[i].first)now+=query[i].second;

      if(now<0){
        isok=false;
        break;
      }
    }

    if(isok)right=mid;
    else left=mid;
  }

  ll min=right;

  left=-1;right=n;

  while(right-left>1){
    ll mid=left+(right-left)/2;

    ll now=mid;
    bool isok=true;

    rep(i,0,q){
      if(s[now]==query[i].first)now+=query[i].second;

      if(now>=n){
        isok=false;
        break;
      }
    }

    if(isok)left=mid;
    else right=mid;
  }

  std::cout<<left-min+1;

  return 0;
}



