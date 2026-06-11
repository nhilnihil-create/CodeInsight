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
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    // 各文字列に含まれる"AB"の数を数える
    vector<ll> cnt(n);
    rep(i, n){
        for(ll pos=0; pos<s[i].size()-1; pos++){
            if(s[i][pos] == 'A' && s[i][pos+1] == 'B') cnt[i]++, pos++;
        }
    }
    ll ans = 0;
    ll bCnt = 0, aCnt = 0, abCnt = 0;
    rep(i, n){
        ans += cnt[i];
        if(s[i][0] == 'B') (s[i][s[i].size()-1] == 'A') ? abCnt++ : bCnt++;
        else if(s[i][s[i].size()-1] == 'A') aCnt++;
    }
    cout << ans + (aCnt+bCnt == 0 && abCnt > 0 ? abCnt-1 : abCnt+min(aCnt, bCnt)) << endl;
}