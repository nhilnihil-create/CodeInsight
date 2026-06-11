#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL (1LL<<62) // 9223372036854775807
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

// 4方向（左、右、上、下）（左上を0, 0とした場合）
vector<long long> dx = {-1, 1, 0, 0};
vector<long long> dy = { 0, 0,-1, 1};
map<char, long long> DirectionToInt = {{'L', 0}, {'R', 1}, {'U', 2},{'D', 3}};

int main(){
    Init();
    ll h, w, n, sr, sc;
    cin >> h >> w >> n >> sr >> sc;
    sr--, sc--;
    string s, t;
    cin >> s >> t;

    // // 高橋くんと青木くんはiステップ目には、si, tiの方向に移動させるか何もしないか選択する。
    // // 高橋くんはマス外に移動させたら勝ち、青木くんはnステップまでマス内に残したら勝ち
    // // 高橋くんだけが動かせる場合、そもそも達成可能かどうかをチェック
    // map<ll, ll> cnt;
    // rep(i, n) cnt[DirectionToInt[s[i]]]++;
    // vector<bool> twin(4, false);
    // if(sc - cnt[0] <  0) twin[0] = true;
    // if(sc + cnt[1] >= w) twin[1] = true;
    // if(sr - cnt[2] <  0) twin[2] = true;
    // if(sr + cnt[3] >= h) twin[3] = true;

    // // 青木くんは一切動かさなくても高橋くんが勝てない場合
    // if(!twin[0] && !twin[1] && !twin[2] && !twin[3]){
    //     YES();
    //     return 0;
    // }

    // iステップ目に青木くんがいて大丈夫な範囲を求める
    // LR
    ll l = 0, r = w;
    for(ll i=n-1; i>=0; i--){
        // 青木くんの移動
        if(t[i] == 'R' && l > 0) l--;
        else if(t[i] == 'L' && r < w) r++;

        // 高橋くんの移動
        if(s[i] == 'R') r--;
        else if(s[i] == 'L') l++;

        if(l >= r){
            NO();
            return 0;
        }
    }

    // UD
    ll u = 0, d = h;
    for(ll i=n-1; i>=0; i--){
        // 青木くんの移動
        if(t[i] == 'D' && u > 0) u--;
        else if(t[i] == 'U' && d < h) d++;

        // 高橋くんの移動
        if(s[i] == 'D') d--;
        else if(s[i] == 'U') u++;

        if(u >= d){
            NO();
            return 0;
        }
    }

    (sc < l || sc >= r || sr < u || sr >= d) ? NO() : YES();
}