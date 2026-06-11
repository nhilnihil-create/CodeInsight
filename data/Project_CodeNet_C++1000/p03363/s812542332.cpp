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

// 累積和が等しくなる2点を選ぶ組み合わせを考えれば良い。

int main(){
    Init();
    ll n; cin >> n;
    vi a(n), sum(n+1, 0);
    ll ans = 0;
    rep(i, n){
        cin >> a[i];
        sum[i+1] += a[i] + sum[i];
    }
    map<ll, ll> cnt;
    rep(i, n+1) cnt[sum[i]]++;
    for(auto &num: cnt) if(num.second >= 2) ans +=(num.second*(num.second-1)/2);
    cout << ans << endl;
}