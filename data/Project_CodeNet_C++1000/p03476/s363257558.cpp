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
int MAX = 101010;
    vector<int> is_prime(MAX, 1);
    is_prime[0] = 0, is_prime[1] = 0;
    for (int i = 2; i < MAX; ++i) {
        if (!is_prime[i]) continue;
        for (int j = i*2; j < MAX; j += i) is_prime[j] = 0;
    }
int count[100001];
count[0]=0;
rep3(i,100000){
 if((i%2==1)&&(is_prime[i])&&(is_prime[(i+1)/2])){
   count[i]=count[i-1]+1;
 }
 else{
   count[i]=count[i-1];
 } 

}

int Q;
cin>>Q;
ll ans[Q];
rep(i,Q){
  int l,r;
  cin>>l>>r;
  ans[i]=count[r]-count[l-1];
}
rep(i,Q){
  cout<<ans[i]<<endl;
}


return 0;
}
