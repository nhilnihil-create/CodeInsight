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
    // 入力
    Init();
    ll n;
    cin >> n;
    vi c(n);
    map<ll, ll> cnt;
    rep(i, n) cin >> c[i];
    
    // dp; i番目の文字まででありうるものの個数
    vi dp(n+1, 0);
    dp[0] = 1;

    for(ll i=1; i<=n; i++){
        // 1つ前までの結果を受け取る
        dp[i] = dp[i-1];
        // 一つ前と同じ文字なら特に処理無し
        if(i >= 2 && c[i-1] == c[i-2]) continue;
        // 今見ている文字がこれまでに出てきていたらひっくり返すことを考える
        dp[i] += cnt[c[i-1]];
        dp[i] %= MODV;
        cnt[c[i-1]] += dp[i-1];
        cnt[c[i-1]] %= MODV;
    }
    cout << dp[n]%MODV << endl;
}