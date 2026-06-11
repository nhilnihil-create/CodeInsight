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

bool isFall(string &s, vector<pair<char, char>> &cmd, ll pos, char goal){
    bool ret = false;
    ll cmdSize = cmd.size();
    rep(i, cmdSize){
        // 現在位置が呪文の対象の場合
        if(cmd[i].first == s[pos]){
            cmd[i].second == 'R' ? pos++ : pos--;
            if(pos < 0 || pos > s.size()-1) break;
        }
    }
    if((pos < 0 && goal == 'L') || (pos > s.size()-1 && goal == 'R')) ret = true;
    return ret;
}

int main(){
    Init();
    ll n, q; string s;
    cin >> n >> q >> s;
    vector<pair<char, char>> cmd(q);
    rep(i, q) cin >> cmd[i].first >> cmd[i].second;

    // 左方向に落ちるゴーレムの中で最も右側にあるものを求める
    ll l = -1, r = n;
    while(r-l > 1){
        ll mid = (r+l)/2;
        (isFall(s, cmd, mid, 'L') ? l : r) = mid;
    }

    // 右方向に落ちるゴーレムの中で最も左側にあるものを求める
    ll ans = n-(l != -1 ? (l+1) : 0);
    l = -1, r = n;
    while(r-l > 1){
        ll mid = (r+l)/2;
        (isFall(s, cmd, mid, 'R') ? r : l) = mid;
    }
    cout << max(0LL, ans-(r != n ? (n-r) : 0))  << endl;
}