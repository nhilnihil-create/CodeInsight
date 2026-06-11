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
    ll n; cin >> n;
    vi a(n), b(n), sum(2, 0);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) sum[0] += a[i], sum[1] += b[i];

    // 操作可能な回数
    // ；1回操作すると、sum[0]は2増え、sum[1]は1増えるため、差分が操作回数である。
    ll k = sum[1] - sum[0];

    // 操作が必要な回数
    ll cnt = 0;
    rep(i, n){
        if(a[i] < b[i]) cnt += ceil((b[i]-a[i])/2.0);
    }
    (k >= cnt) ? Yes() : No(); 
}