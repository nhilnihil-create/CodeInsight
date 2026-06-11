#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll n, k; cin >> n >> k;

    // a, b, cは整数、ansは条件を満たす組数
    ll a, b, c, ans = 0;

    // k|a+b && k|b+c && k|c+aより、k|2a && k|2b && k|2cである
    if(k%2 == 0){
        // kが偶数の場合、a, b, cは必ずk/2の倍数となる
        ll multi_k = floor(n/k);
        ll multi_kd2 = floor(n/(k/2));
        multi_kd2 -= multi_k;
        ans = pow(multi_k, 3) + pow(multi_kd2, 3);
    }
    else{
        // kが奇数の場合、a, b, cは必ずkの倍数となる
        ll multi = floor(n/k);
        ans = multi * multi * multi;
    }
    
    // 結果の出力
    cout << ans <<endl;
}