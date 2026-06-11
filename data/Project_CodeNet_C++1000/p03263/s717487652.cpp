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
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    
    // 入力処理
    ll h, w; cin >> h >> w;
    vvi a(h, vi(w, 0));

    // 入力処理＋移動処理
    vi y, x, yd, xd;
    rep(i, h) rep(j, w){
        // 入力値を受け付けて、移動値と合算する
        ll in; cin >> in;
        a[i][j] += in;

        // 入力値＋移動値が偶数なら移動操作は不要なので移動処理を飛ばす
        if(a[i][j]%2 == 0) continue;
        
        // 入力値＋移動値が奇数の場合はまず右に動かせるか確認する
        if(j != w-1){
            // 現在位置から-1し右に+1する
            a[i][j]--; a[i][j+1]++;
            // 移動結果を1-Basedで記録する
            y.push_back(i+1); x.push_back(j+1);
            yd.push_back(i+1); xd.push_back(j+2);
        }

        // 右に動かせない場合は下に動かせるか確認する
        else if(i != h-1){
            // 現在位置から-1し下に+1する
            a[i][j]--; a[i+1][j]++;
            // 移動結果を1-Basedで記録する
            y.push_back(i+1); x.push_back(j+1);
            yd.push_back(i+2); xd.push_back(j+1);
        }
    }

    // 出力処理
    cout << y.size() << endl;
    rep(i, y.size()) cout << y[i] << " " << x[i] << " " << yd[i] << " " << xd[i] << endl;
}