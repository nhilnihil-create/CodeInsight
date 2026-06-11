#include <assert.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <complex>
#include <deque>
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
#define debug(i) std::cout << i << "\n"

const ll MOD = 1000000007;

bool dp[4000][16000];

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  std::string s;
  std::cin >> s;
  ll x, y,n;
  n=s.size();
  std::cin >> x >> y;
  std::vector<ll> xlen, ylen;
  ll mode = 1, temp = 0;
  rep(i, 0, n ){
    if (s[i] == 'T') {
      if (mode == 1) {
        xlen.push_back(temp);
      } else {
        ylen.push_back(temp);
      }
      mode *= -1;
      temp = 0;
    } else {
      temp++;
    }
  }

  if (mode == 1) {
    xlen.push_back(temp);
  } else {
    ylen.push_back(temp);
  }

  ylen.push_back(0);

  bool ans=true;

  rep(i,0,16000)dp[0][i]=false;
  dp[0][xlen[0]+8000]=true;
  rep(i,1,xlen.size()){
    rep(j,0,16000){
      dp[i][j]=((j-xlen[i]>=0)&&dp[i-1][j-xlen[i]])||((j+xlen[i]<16000)&&dp[i-1][j+xlen[i]]);
    }
  }
  ans= (ans&&dp[xlen.size()-1][x+8000]);


  rep(i,0,16000){
    dp[0][i]=false;
  }
  dp[0][8000+ylen[0]]=true;
  dp[0][8000-ylen[0]]=true;
  rep(i,1,ylen.size()){
    rep(j,0,16000){
      dp[i][j]=((j-ylen[i]>=0)&&dp[i-1][j-ylen[i]])||((j+ylen[i]<16000)&&dp[i-1][j+ylen[i]]);
    }
  }
  ans=(ans&&dp[ylen.size()-1][y+8000]);
  if(ans){
    std::cout<<"Yes";
  }else{
    std::cout<<"No";
  }
  return 0;
}