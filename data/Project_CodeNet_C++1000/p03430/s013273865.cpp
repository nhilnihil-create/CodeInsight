#include <cassert>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <chrono>
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
#include <limits>
#include "limits.h"
 
#define rep(i, a, b) for (long long (i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void debug_out(){std::cerr<<std::endl;}

template<typename Head,typename... Tail>
void debug_out(Head h,Tail... t){
  std::cerr<<" "<<h;
  debug_out(t...);
}
 
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
  if(b==0)return 1;
  if ((a == 0)||(mod!=-1&&(a+mod)%mod==0)) {
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
using P=std::pair<long long,long long>;

ll dp[310][310][310]={0};

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string s;
  std::cin>>s;

  ll k;
  std::cin>>k;

  ll n=s.size();

  rep(i,0,n)rep(j,0,k+1)dp[i][i][j]=0;
  rep(i,0,n)rep(j,0,k+1)dp[i][i+1][j]=1;

  rep(len,2,n+1){
    rep(i,0,n-len+1){
      if(s[i]==s[i+len-1]){
        rep(j,0,k+1){
          dp[i][i+len][j]=dp[i+1][i+len-1][j]+2;
        }
      }else{
        rep(j,0,k+1){
          chmax(dp[i][i+len][j],dp[i+1][i+len][j]);
          chmax(dp[i][i+len][j],dp[i][i+len-1][j]);
          if(j==0){
            chmax(dp[i][i+len][j],dp[i+1][i+len-1][j]);      
          }else{
            chmax(dp[i][i+len][j],dp[i+1][i+len-1][j]);      
            chmax(dp[i][i+len][j],dp[i+1][i+len-1][j-1]+2);
          }
        }
      }
    }
  }

  std::cout<<dp[0][n][k]<<"\n";

  return 0;
}