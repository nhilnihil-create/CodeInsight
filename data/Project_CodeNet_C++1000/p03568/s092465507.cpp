#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
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

// 数列の全ての要素が奇数だと積が偶数とならない。
// したがって、1つ以上の要素が偶数であり、かつ全ての要素が0より大きい組み合わせを考える。

int main(){
    Init();
    ll n; cin >> n;

    ll ans = 1;
    ll sub = 1;
    rep(i, n){
        ll a; cin >> a;
        ans *= 3;
        sub *= (a%2 == 0 ? 2 : 1);
    }
    // 全部が奇数の場合を引く
    cout << ans-sub << endl;
}