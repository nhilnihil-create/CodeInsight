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

int main(){
    Init();
    ll k, a, b;
    cin >> k >> a >> b;

    // 単純に叩き続けた場合
    ll ans1 = 1+k;
    
    // 2回の操作で[ビスケットA枚をB枚にする]→2操作でB-A枚増やす
    // A>B+1じゃない場合、単純に叩き続けた場合で解決
    k -= (a-1);
    ll ans2 = a + (b-a)*(k/2) + (k%2 == 1 ? 1 : 0);

    // 大きい方を出力
    cout << max(ans1, ans2) << endl;
}