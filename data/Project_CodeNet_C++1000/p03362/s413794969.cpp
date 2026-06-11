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
using pll = pair<ll,ll>;
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
using mat = vector<vector<ll>>;
using vec = vector<ll>;
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

// エラトステネスのふるい
    int MAX = 101010;
    vector<int> is_prime(MAX, 1);
    is_prime[0] = 0, is_prime[1] = 0;
    for (int i = 2; i < MAX; ++i) {
        if (!is_prime[i]) continue;
        for (int j = i*2; j < MAX; j += i) is_prime[j] = 0;
    }

    int N;
    cin>>N;
    vector<int> ans;
    int p=2;
    while(ans.size()<N){
        if((p%5==2)&&(is_prime[p]))ans.push_back(p);
        p++;

    }
    rep(i,N){
        cout<<ans[i];
        if(i!=N-1)cout<<" ";
        else cout<<endl;
    }

return 0;
}