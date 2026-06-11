/*
dpで書いたやつの解説

”i円までの最適を考える”
という感じで考える

i円集めるには高々i回
操作すればいいので
各要素をdp[i]=iで初期化

要素の個数は
9^7=4782969なので
5000000くらいあれば
十分

あとは配るdpで各要素を
最小化する

dp[n]を出力

補足として
要素数に十分ゆとりがあるから
i番目をi円集める最小
にするとわかりやすいかなと思って
出力がdp[n]でよい

では本文をどうぞ
*/
#include <bits/stdc++.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<iostream>
#include <vector>
#include <cstdlib>
using namespace std;
 
template <class T> using V = vector<T>;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1LL << 60;
 
using ll = long long;
using db = double;
using st = string;
using ch = char;
using bl = bool;
using vll = V<ll>;
using vpll =V<pair<ll,ll>>;
using vst = V<st>;
using vdb = V<db>;
using vch = V<ch>;
using vbl = V<bl>;
 
 
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define rFOR(i,a,b) for(ll i=(a);i>(b);i--)
#define oFOR(i,a,b) for(ll i=(a);i<(b);i+=2)
#define bgn begin()
#define en end()
#define SORT(a) sort((a).bgn,(a).en)
#define REV(a) reverse((a).bgn,(a).en)
#define M(a,b) max(a,b)
#define rM(a,b) min(a,b)
#define fi first
#define se second
#define sz size()
#define gcd(a,b) __gcd(a,b)
#define co(a) cout<<a<<endl;
#define ci(a) cin>>a;
 
 
ll sum(ll n) {
  ll m=0;
  FOR(i,0,20){
    m+=n%10;
    n/=10;
    if(n==0){
      break;
    }
  }
  return m;
}
 
 
ll combi(ll n,ll m) {
  ll ans=1;
  rFOR(i,n,n-m){
    ans*=i;
  }
  FOR(i,1,m+1){
    ans/=i;
  }
  return ans;
}
 
 
ll lcm(ll a,ll b){
  ll n;
  n=a/gcd(a,b)*b;
  return n;
}
 
 
/****************************************\
| Thank you for viewing my code:)        |
| Written by RedSpica a.k.a. RanseMirage |
| Twitter:@asakaakasaka                  | 
\****************************************/
 
 
signed main() {
  ll n; cin>>n;
  vll dp(5000000);
  FOR(i,1,5000000){
    dp[i]=i;
  }
  FOR(i,0,n){
    FOR(j,0,8){
      ll a=pow(6,j);
      ll b=pow(9,j);
      chmin(dp[i+a],dp[i]+1);
      chmin(dp[i+b],dp[i]+1);
    }
  }
  cout<<dp[n]<<"\n";
}