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
    ll n, ans = INFLL; string s;
    cin >> n >> s;

    // i番目以降を黒に変える場合の個数
    vi chgcnt(n+1, 0);
    for(ll i=n-1; i>=0; i--){
        chgcnt[i] = chgcnt[i+1];
        if(s[i] == '.') chgcnt[i]++;
    }

    ll cnt = 0;
    rep(i, n){
        if(s[i] == '#') cnt++;
        chmin(ans, cnt+chgcnt[i+1]);
    }

    // 黒のとなりに白があったら黒に変えるパターン
    cnt = 0;
    rep(i, n){
        if(s[i] == '#' && i != n-1){
            if(s[i+1] == '.'){
                s[i+1] = '#';
                cnt++;
            }
        }
    }
    cout << min(ans, cnt) << endl;
}