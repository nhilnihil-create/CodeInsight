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
int calc(int N){
  if(N==0){
    return 0;

  }
  else{
    return N*calc(N-1);
  }
}

int main() {
  ll N;
cin>>N;
string S[N];
ll alp_num[5];
ll count=0;
rep(i,5){
  alp_num[i]=0;
}
rep(i,N){
  
  cin>>S[i];
  if(S[i][0]=='M'){
    count++;
    alp_num[0]++;


  }
  else if(S[i][0]=='A'){
    count++;
    alp_num[1]++;
  }
  else if(S[i][0]=='R'){
    count++;
    alp_num[2]++;
  }
  else if(S[i][0]=='C'){
    count++;
    alp_num[3]++;
  }
  else if(S[i][0]=='H'){
    count++;
    alp_num[4]++;
  }
  
}
ll ans=0;
rep(i,5){
  rep2(j,i+1,5){
    rep2(k,j+1,5){
      ans+=alp_num[i]*alp_num[j]*alp_num[k];
    }
  }
}
cout<<ans<<endl;
return 0;
}