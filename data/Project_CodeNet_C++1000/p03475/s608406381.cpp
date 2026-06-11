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
  int N;
  cin>>N;
  int stat[N-1][3];//0;列車時間　１，スタート　２，間隔
  rep(i,N-1){
    rep(j,3){
      cin>>stat[i][j];
    }
  }
  int time[N][N];
  rep(i,N){
    time[i][i]=0;
  }
  rep(i,N){
    rep2(j,i,N-1){
      if(time[i][j]<stat[j][1]){
        time[i][j+1]=stat[j][1]+stat[j][0];
      }
      else if(time[i][j]%stat[j][2]==0){
        time[i][j+1]=time[i][j]+stat[j][0];
      }
      else{
        time[i][j+1]=(time[i][j]/stat[j][2]+1)*stat[j][2]+stat[j][0];
      }

    }
  }
  rep(i,N){
    cout<<time[i][N-1]<<endl;
  }
return 0;
}

