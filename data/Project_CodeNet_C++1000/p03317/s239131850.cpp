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

// 操作の必要回数を計算する
ll repOp(ll dist, ll k){ return ceil(1.0*dist/(k-1)); }

int main(){
    Init();
    ll n, k, pos, ans = INFLL; cin >> n >> k; vi a(n);
    // 入力処理・最小値(1)の添字を取得
    rep(i, n){ cin >> a[i]; if(a[i] == 1) pos = i; }
    // nとkが等しい場合は1回の操作で終了する
    if(n == k) ans = 1;
    // nとkが等しくない場合は左右に何回の操作が必要か分けて計算する
    else{
        // 最初の操作の仕方をk通り試す
        for(ll i=0; i<k; i++){
            // 左右どちらかにはみ出る操作の仕方は飛ばす
            if(pos-i < 0 || pos+(k-1)-i > n-1) continue;
            // 1回操作を行ったのち、最左の1と最右の1からそれぞれ左右に何回操作が必要か計算する
            ll tmp = 1 + repOp(abs(0-(pos-i)), k) + repOp(abs(n-1-(pos+(k-1)-i)), k);
            // 最小値の更新
            chmin(ans, tmp);
        }
    }
    // 出力処理
    cout << ans << endl;
}