#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

void print(Vl vec){
    rep(i, 0, sz(vec)){
        if(i) cout << " ";
        cout << vec[i];
    }
    coel;
}

////////////////////////////////////////////////////////

//　各数字を1に変えるのに必要な魔力を求めたい
//　全点対最短経路　ワーシャルフロイド O(V^3)

vector<Vl> G(10, Vl(10));

int main() {
    ll h, w; cin >> h >> w;
    rep(i, 0, 10){
        rep(j, 0, 10){
            cin >> G[i][j];
        }
    }
    Vl a(h*w);
    rep(i, 0, h*w) cin >> a[i];

    rep(k, 0, 10){
        rep(i, 0, 10){
            rep(j, 0, 10){
                chmin(G[i][j], G[i][k]+G[k][j]);
            }
        }
    }
    ll ans = 0;
    rep(i, 0, h*w){
        if(a[i] == -1) continue;
        ans += G[a[i]][1];
    }
    co(ans);

    return 0;
}
