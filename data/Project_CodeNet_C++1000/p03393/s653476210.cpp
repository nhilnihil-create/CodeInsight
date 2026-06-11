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
    string S,ans="";
    cin>>S;
    if(S.size()<26){
    map<char,int> m;
    rep(i,S.size()){
        m[S[i]]++;
    }
    rep(i,26){
        if(m[(char)(i+'a')]==0){
            ans= S+string(1,(char)(i+'a'));
            break;
        }
    }

    }
    else{
        if(S[0]=='z'){
            cout<<-1<<endl;
            return 0;
        }
    vector<int> order(26);
    rep(i,26){
        order[i]=S[i]-'a';
    }
    

    
    next_permutation(order.begin(), order.end());
    rep(i,26){
       
        ans+=string(1,(char)(order[i]+'a'));
        if(S[i]!=(char)(order[i]+'a')){
            break;
        }


    }
    }
    // 答えを出力
    cout << ans << endl;
return 0;
}