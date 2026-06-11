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
#define repr4(i,s,n) for(ll i = (n);i>=(s);i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
using Graphw = vector<vector<pair<ll,ll>>>;
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
const int mod = 1000000007;



int main(){

int N;
cin>>N;
ll K,A[N];
cin>>K;
rep(i,N){
    cin>>A[i];
}
ll bitsum[40][2];
rep(i,40)rep(j,2)bitsum[i][j]=0;
rep(i,40){
    rep(j,N){
        if(A[j]&(1LL<<i)){
            bitsum[i][1]++;
        }
        else{
            bitsum[i][0]++;
        }
    }
}
bool kbit[40];
rep(i,40)kbit[i]=(K>>i)&1;
ll dp[41][2];
memset(dp,-1,sizeof(dp));
dp[40][1]=0;
repr(i,40){
    if(kbit[i]){
        dp[i][1]=dp[i+1][1]+bitsum[i][0]*(1LL<<i);
        dp[i][0]=dp[i+1][1]+bitsum[i][1]*(1LL<<i);
        if(dp[i+1][0]!=-1){
        dp[i][0]=max(dp[i][0],dp[i+1][0]+max(bitsum[i][1],bitsum[i][0])*(1LL<<i));
        }
    }
    else{
        dp[i][1]=dp[i+1][1]+bitsum[i][1]*(1LL<<i);
        if(dp[i+1][0]!=-1){
        dp[i][0]=dp[i+1][0]+max(bitsum[i][1],bitsum[i][0])*(1LL<<i);
        }

    }
    
   
}
cout<<max(dp[0][0],dp[0][1])<<endl;
return 0;

return 0;
}