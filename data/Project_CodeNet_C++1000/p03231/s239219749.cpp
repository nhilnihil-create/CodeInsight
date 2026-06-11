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

// 最大公倍数長が最適解の候補
// n/最大公約数, m/最大公約数毎に重なる文字が出現するので、
// そこでミスマッチが生じないかチェックする

long long lcm(long long a, long long b){ return a/__gcd(a, b)*b; }

int main(){
    Init();
    ll n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    ll num = lcm(n, m);
    bool chk = true;
    ll gcdn = __gcd(n, m);
    ll step_n = n/gcdn, step_m = m/gcdn;
    for(ll i=0; i<gcdn; i++) if(s[step_n*i] != t[step_m*i]) chk = false;
    cout << (chk ? num : -1) << endl; 
}