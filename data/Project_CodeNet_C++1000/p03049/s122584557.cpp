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



int main() {
int N;
cin>>N;
string S[N];
rep(i,N){
    cin>>S[i];
}
int in_count=0;
rep(i,N){
    rep(j,S[i].size()-1){
        if((S[i][j]=='A')&&(S[i][j+1]=='B')){
            in_count++;
        }

    }
}
int edge[3];//0両端　B A 1左B 2 右A 
rep(i,3){
    edge[i]=0;
}
rep(i,N){
    if((S[i][0]=='B')&&(S[i][S[i].size()-1]=='A'))edge[0]++;
    else if(S[i][0]=='B')edge[1]++;
    else if(S[i][S[i].size()-1]=='A')edge[2]++;
}
int ans=0;


if((edge[1]==0)&&(edge[2]==0)){
    ans+=max(0,edge[0]-1);
}
else{
    ans+=min(edge[1],edge[2]);
    ans+=edge[0];
}
cout<<in_count+ans<<endl;
return 0;
}
