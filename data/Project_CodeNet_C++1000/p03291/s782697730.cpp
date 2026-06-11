#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

int main(){
  string s;
  cin >> s;
  int ssize = (int)s.size();
  vector<ll> md3n;
  ll tp = 1;
  rep(i,101000){
    md3n.pb(tp); tp*=3; tp %= mod;
  }

  int count_ = 0;
  vector<vector<ll>> dp(3,vector<ll>(ssize));
  rep(y,3) rep(x,ssize) dp[y][x]=0;
  ll Acnt = 0;
  rep(i,ssize){
    if(s[i]!='?'){
      if(s[i]=='A') {
        Acnt += md3n[count_];
        Acnt %= mod;
      }
      dp[0][i] = Acnt % mod;

      if(i==0) continue;

      dp[1][i] = dp[1][i-1];
      if(s[i]=='B') dp[1][i] += dp[0][i];
      dp[1][i]%=mod;

      dp[2][i] = dp[2][i-1];
      if(s[i]=='C') dp[2][i] += dp[1][i];
      dp[2][i] %= mod;
    }
    else{

      if(i==0){ dp[0][0]=1; Acnt++; count_++; continue; }
      ll tmp[3][3];
      tmp[0][0] = tmp[0][1] = tmp[0][2] = dp[0][i-1];
      tmp[0][0]+=md3n[count_]; tmp[0][0] %= mod;

      tmp[1][0] = tmp[1][1] = tmp[1][2] = dp[1][i-1];
      tmp[1][1] += tmp[0][1]; tmp[1][1] %= mod;

      tmp[2][0] = tmp[2][1] = tmp[2][2] = dp[2][i-1];
      tmp[2][2] += tmp[1][2]; tmp[2][2] %= mod;

      dp[0][i] = tmp[0][0]+tmp[0][1]+tmp[0][2];
      dp[1][i] = tmp[1][0]+tmp[1][1]+tmp[1][2];
      dp[2][i] = tmp[2][0]+tmp[2][1]+tmp[2][2];
      dp[0][i] %= mod;
      dp[1][i] %= mod;
      dp[2][i] %= mod;

      Acnt = Acnt*3 + md3n[count_];
      Acnt %= mod;
      count_++;
    }
  }

  rep(y,3){
    rep(x,ssize){
      //cout << dp[y][x] << " " ;
    }
    //cout << endl;
  }

  cout << (dp[2][ssize-1])%mod << endl;
  return 0;
}
/*
    ABCBC
  A 11111
 AB 01122 //AB = AB + A
ABC 00113 //ABC = ABC + AB

    A??C A AA AB AC A? A?A A?B A?C A?? A??C
  A ???? 1 12 11 11 14 147 144 144 14F 14FF
 AB ???? 0 00 01 00 01 011 015 011 017 0177
ABC ???8 0 00 00 00 00 000 000 001 001 0018

    ??BC A B C ? ?A ?B ?C ?? ??B ??BC
  A ???? 1 0 0 1 14 11 11 16 166 1666
 AB ???? 0 0 0 0 00 01 00 01 017 0177
ABC ???? 0 0 0 0 00 00 00 00 000 0007

 ??A ? ?? ??A
A    1 16 16F

    ??ABC ? ?? ??A ??A-B  ??A-B-C
  A       1 16 16F 16F F  16F F F
 AB       0 01 011 011 10 011 1010
ABC       0 00 000 000 0  000 0 10

AAABC 3
ABABC 3
ACABC 2
BAABC 2
BBABC 1
BCABC 1
CAABC 2
CBABC 1
CCABC 1

A B C
AA AB AC BA BB BC CA CB CC
*/
