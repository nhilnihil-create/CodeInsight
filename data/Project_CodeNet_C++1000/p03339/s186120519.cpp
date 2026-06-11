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

int main(){
    Init();
    // 入力処理
    ll n, ans = INFLL; string s; cin >> n >> s;

    // 左右両方から累積和を計算
    vi rw(n, 0), le(n, 0);
    rep(i, n){
        // 右方向に西向きの人数の累積和を取る
        if(s[i] == 'W') (i == 0) ? rw[i] = 1 : rw[i] = rw[i-1] + 1; 
        else (i == 0) ? rw[i] = 0 : rw[i] = rw[i-1]; 
        // 左方向に東向きの人数の累積和を取る
        if(s[n-1-i] == 'E') (i == 0) ? le[n-1-i] = 1 : le[n-1-i] = le[n-1-i+1] + 1;
        else (i == 0) ? le[n-1-i] = 0 : le[n-1-i] = le[n-1-i+1];
    }

    // i番目にリーダを配置した時に向きを変更する人数を算出
    rep(i, n){
        ll tmp = 0;
        // 左端の場合
        if(i == 0) tmp = le[i+1];
        // 右端の場合
        else if(i == n-1) tmp = rw[i-2];
        // 両端以外の場合
        else tmp = rw[i-1] + le[i+1];
        // 最小値の更新
        chmin(ans, tmp);
    }

    // 結果の出力
    cout << ans << endl;
}