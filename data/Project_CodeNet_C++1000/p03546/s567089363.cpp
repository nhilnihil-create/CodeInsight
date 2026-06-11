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

ll root(ll pa, ll node, ll cost, vvi &c, vi &minmp){
    if(node == 1){
        chmin(minmp[pa], cost);
        return cost;
    }
    ll mincost = INFLL;
    for(ll i=0; i<10; i++){
        // 自分自身なら飛ばす
        if(i == node) continue;
        // 現在の最小値より小さい変更先があるなら試してみる
        if(cost + c[node][i] < minmp[pa]){
            chmin(mincost, root(pa, i, cost+c[node][i], c, minmp));
        }
    }
    return mincost;
}

int main(){
    Init();
    ll h, w; cin >> h >> w;
    vvi c(10, vi(10, 0));
    vi minmp(10);

    // i -> jへの移動に必要な魔力を入力
    rep(i, 10){
        rep(j, 10){
            cin >> c[i][j];
            // 0~9から直接1に変更するのに必要な魔力を入れておく
            if(j==1) minmp[i] = c[i][j];
        }
    }

    // 0~9の各数値を1に変更するのに必要な最小値を求める
    for(ll i=0; i<10; i++){
        // 1は自明（mp=0）なので飛ばす
        if(i == 1) continue;
        root(i, i, 0, c, minmp);
    }

    // h*wで1と-1を除く数字を1にする魔力の総和を求める
    ll total = 0;
    rep(i, h){
        rep(j, w){
            ll tmp; cin >> tmp;
            if(tmp != 1 && tmp != (-1)) total += minmp[tmp];
        }
    }
    cout << total << endl;
}