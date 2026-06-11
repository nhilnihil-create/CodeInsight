/*#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#include <boost/rational.hpp>
*/
#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define rep3(i, n) for (ll i = 1; i < (ll)(n+1); i++)
#define rep4(i, s, n) for (ll i = (s); i < (ll)(n+1); i++)
#define repr(i,n) for (ll i = (n-1); i>=0;i--)
#define repr3(i,n) for(ll i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
#define INF1  INT_MAX;
#define INF2  LLONG_MAX;
#define PI  3.14159265358979323846;
#define MOD 1000000007;
/*
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部長が32の浮動小数点数型
using Real32 = mp::number<mp::cpp_dec_float<32>>;
// 仮数部長が1024の浮動小数点数型
using Real1024 = mp::number<mp::cpp_dec_float<1024>>;
// 有理数型
using Rat = boost::rational<Bint>;
*/


int main() {
  int H,W;
  cin>>H>>W;
  int dp[10][10];
  rep(i,10){
    rep(j,10){
      dp[i][j]=10000001;
    }
  }
  int c;
  rep(i,10){
    rep(j,10){
      cin>>c;
      dp[i][j]=c;
    }
  }

  for(int k=0;k<10;k++){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    }
}
ll ans=0;
int A;
rep(i,H){
  rep(j,W){
    cin>>A;
    if(A!=-1){
    ans+=dp[A][1];
    }
  }
}
cout<<ans<<endl;
return 0;
}


