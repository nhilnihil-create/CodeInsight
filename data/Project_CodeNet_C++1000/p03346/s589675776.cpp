#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL (1LL<<60)
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
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

// 間に数字を挿入したり出来ないため、移動しない数字の相対的な順序は変わらない。
// 先頭から見ていき、単調増加となっている最大の部分集合を求め、
// nからその部分集合の要素数を減算したものが解となる。

int main(){
    // 入力
    Init();
    ll n; cin >> n;
    vi p(n);
    rep(i, n) cin >> p[i];

    // dpで単調増加となっている最大の部分集合を求める
    // dp[i]; 数字iより前に出現した数字で、かつ数字i以下の数字の連続部分（差は1）
    vi dp(n+1, 0);
    ll maxval = 0;
    rep(i, n){
        if(dp[p[i]-1] == 0) dp[p[i]] = 1;
        else dp[p[i]] = dp[p[i]-1] + 1;
        chmax(maxval, dp[p[i]]);
    }
    cout << n-maxval << endl;
    return 0;
}