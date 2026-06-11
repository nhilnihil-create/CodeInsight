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
    ll n, k, ans = INFLL; cin >> n >> k;
    vi x(n);

    // 入力処理と始点の探索
    ll sp = INFLL;
    rep(i, n){
        cin >> x[i];
        if(sp == INFLL && x[i]>=0) sp = i;
        if(x[i] < 0) x[i] *= -1;
    }
    // 始点に0を挿入
    if(sp != INFLL) x.insert(x.begin()+sp, 0);
    else { x.push_back(0); sp = n; }
    n++;

    // 右方向にi本ロウソクを点ける
    for(ll i=1; i<=k; i++){
        // 左方向でk-i本ロウソクを点ける
        ll j = k-i;
        // もし範囲からはみ出る本数が指定されるなら飛ばす
        if(sp+i >= n || sp-j < 0) continue;
        // 右方向にi本ロウソクを点ける
        ll calc = x[sp+i];
        // 左方向に進む必要があるなら戻る分も考慮して移動量を算出
        if(j >= 1) calc += x[sp+i]+x[sp-j];
        // 最小値の更新
        chmin(ans, calc);
    }

    // 左方向にi本ロウソクを点ける
    for(ll i=1; i<=k; i++){
        // 右方向でk-i本ロウソクを点ける
        ll j = k-i;
        // もし範囲からはみ出る本数が指定されるなら飛ばす
        if(sp+j >= n || sp-i < 0) continue;
        // 左方向にi本ロウソクを点ける
        ll calc = x[sp-i];
        // 右方向に進む必要があるなら戻る分も考慮して移動量を算出
        if(j >= 1) calc += x[sp-i]+x[sp+j];
        // 最小値の更新
        chmin(ans, calc);
    }

    // 最小値の出力
    cout << ans << endl;
}