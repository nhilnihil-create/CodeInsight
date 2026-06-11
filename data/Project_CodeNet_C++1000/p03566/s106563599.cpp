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
 
#define rep(i, a, b) for (long long(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug " << i << std::endl
 
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

using ll = long long;
using P = std::pair<ll, ll>;
 
// const long long MOD = 998244353;
const long long MOD = 1e9 + 7;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  struct Line{
    long double l,r,v;

    long double val(long double x){
      if(x<=l)return v+l-x;
      else if(l<x&&x<=r) return v;
      else return v+x-r;
    }
  };

  ll n;
  std::cin>>n;

  long double sum=0;

  std::vector<Line> lines(n+2);
  rep(i,0,n){
    long double t;
    std::cin>>t;
    lines[i].l=sum;
    lines[i].r=sum+t;
    sum+=t;
  }

  rep(i,0,n){
    long double v;
    std::cin>>v;
    lines[i].v=v;
  }

  lines[n].l=0;lines[n].r=0;lines[n].v=0;
  lines[n+1].l=sum;lines[n+1].r=sum;lines[n+1].v=0;

  long double ans=0;

  long double prv=100.0l;

  rep(i,0,n+2){
    chmin(prv,lines[i].val(0));
  }

  for(long double i=0.5l;i<=sum;i+=0.5l){
    long double temp=100.0l;
    rep(j,0,n+2)chmin(temp,lines[j].val(i));
    ans+=(prv+temp)*0.25l;
    prv=temp;
  }

  std::cout<<std::setprecision(10)<<std::fixed<<ans<<"\n";

  return 0;
}

