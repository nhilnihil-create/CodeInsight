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

void GreaterString(string &s, string t){
    if(s == "-") s = t;
    else if(s.size() < t.size()) s = t; 
    else if(s.size() == t.size()){
        if(s < t) s = t;
    }
}

int main(){
    Init();
    ll n, m;
    cin >> n >> m;
    vi a(m);
    rep(i, m) cin >> a[i];

    // 使う本数(match[0]はダミー)
    ll match[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    // dp[i]; マッチ棒をi本使って作れる最大値
    vector<string> dp(n+10, "-"); dp[0] = "";

    for(ll i=0; i<=n; i++){
        if(dp[i] == "-") continue;
        for(auto num: a){
            GreaterString(dp[i+match[num]], dp[i]+(char)(num+'0'));
        }
    }
    cout << dp[n] << endl;
}