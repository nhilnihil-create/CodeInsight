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

long long modPow(long long x, long long n, long long mod = MODV){
    if(n == 0) return 1;
    if(n%2 == 0) return modPow(x*x%mod, n/2, mod)%mod;
    return x%mod * modPow(x%mod, n-1, mod)%mod;
}

int main(){
    Init();
    ll x, ans = 1; cin >> x;

    // x=1の時は1を出力
    if(x == 1){
        cout << 1 << endl;
        return 0;
    }

    // 実数部
    for(ll i=2; i*i<=x; i++){
        // 指数部
        for(ll p=2; p<=10; p++){
            ll tmp = modPow(i, p);
            if(tmp > x) break;
            chmax(ans, tmp);
        }
    }
    cout << ans << endl;
}