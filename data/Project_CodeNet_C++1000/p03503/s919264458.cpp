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
    ll n, ans = -INFLL; cin >> n;

    // f[i][j][k], i:店番号, j:曜日, k:時間帯
    vvi f(n, vi(10, 0));
    // 全ての店
    rep(i, n){
        // 全ての曜日と午前・午後
        rep(j, 10){
            cin >> f[i][j];
        }
    }

    // 利益計算用
    vector<vector<ll>> p(n, vector<ll>(11, 0));
    rep(i, n){
        rep(j, 11){
            cin >> p[i][j];
        }
    }

    // ビット全探索
    for(ll bit=1; bit<(1LL<<10); bit++){
        vi run(10, 0);
        vi run_cnt(n, 0);
        // 1~10ビット目のマスク -> お姉ちゃんの営業日を決定
        for(ll mask=0; mask<10; mask++) if(bit&(1LL<<mask)) run[mask] = 1;
        for(ll i=0; i<10; i++){
            // 休業日なら飛ばす
            if(!run[i]) continue;
            // 営業日なら他の店の営業状況を調べる
            for(ll j=0; j<n; j++) if(f[j][i]) run_cnt[j]++;
        }
        // 利益の計算
        ll sum = 0;
        for(ll i=0; i<n; i++) sum += p[i][run_cnt[i]];
        // 最大値の更新
        chmax(ans, sum);
    }
    cout << ans << endl;
}