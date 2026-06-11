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
    ll n, ansH; cin >> n;
    vi x(n), y(n), h(n);
    ll minX = INFLL, minY = INFLL, maxX = -1, maxY = -1;

    rep(i, n){
        cin >> x[i] >> y[i] >> h[i];
        chmin(minX, x[i]); // xの最小値
        chmin(minY, y[i]); // yの最小値
        chmax(maxX, x[i]); // xの最大値
        chmax(maxY, y[i]); // yの最大値
    }

    // 中心座標は([minX, maxX], [minY, maxY])に存在するため全探索
    for(ll posX=minX; posX<=maxX; posX++){
        for(ll posY=minY; posY<=maxY; posY++){
            // 初期化
            ansH = -1;
            // 入力された全ての点で矛盾が起きないか探索
            for(ll i=0; i<n; i++){
                // 高さ0のケースは後で確かめるため飛ばす
                if(h[i] == 0) continue;
                // 中心座標の高さ（候補）を求める
                if(ansH == -1) ansH = h[i] + abs(posX-x[i]) + abs(posY-y[i]);
                // 中心座標の高さ（候補）と矛盾がないか確かめる
                else if(ansH != h[i] + abs(posX-x[i]) + abs(posY-y[i])){
                    ansH = -INFLL;
                    break;
                }
            }
            // 矛盾があった場合は中心座標を変えて探索し直す
            if(ansH == -INFLL) continue;

            // 高さ0の入力点で矛盾がないか確認
            for(ll i=0; i<n; i++){
                // 高さが0以外なら前のループで確認済みなので飛ばす
                if(h[i] != 0) continue;
                ll distance = abs(posX-x[i]) + abs(posY-y[i]);
                if(ansH > distance){
                    ansH = -INFLL;
                    break;
                }
            }
            // 矛盾があった場合は中心座標を変えて探索し直す
            if(ansH == -INFLL) continue;

            // 答えの出力
            cout << posX << " " << posY << " " << ansH << endl;
        }
    }
}