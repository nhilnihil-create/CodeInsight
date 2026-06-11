#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll MAX_V = 300;
// d[u][v]は辺（u, v)のコスト
vector<vector<ll> > d(MAX_V, vector<ll>(MAX_V, INF));
// 頂点数
ll V;

void warshall_floyd() {
    rep(k, V){
        rep(i, V){
            rep(j, V){
                chmin(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

// ---------------------------------------------------
// O(|V|^3) すべての２頂点間の最短路を求める(ワーシャル・フロイド法)
// ---------------------------------------------------

int main(){
    ll H, W, cost, a, ans = 0;
    cin >> H >> W;
    V = 10;
    rep(i, V){
        d[i][i] = 0;
    }
    rep(y, 10){
        rep(x, 10){
            cin >> cost;
            d[y][x] = cost;
        }
    }
    warshall_floyd();
    
    rep(h, H){
        rep(w, W){
            cin >> a;
            if(a != -1){
                ans += d[a][1];
            }
        }
    }
    cout << ans << endl;
}