#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}
#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e17;
/* warshall_floyd(dist)
    入力：初期化した dist
    計算量：O(|V|^3)
    副作用：dis[i][j]にiからjへの最短路のコストを格納
*/
void warshall_floyd(vector<vector<long long>> &dist) {
    int V = dist.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<ll>>dist(10,vector<ll>(10,INF));
    rep(i,10) rep(j,10) {
        ll a;
        cin >> a;
        dist[i][j] = a;
    }
    warshall_floyd(dist);
    ll ans = 0;
    rep(i,h) rep(j,w) {
        int a;
        cin >> a;
        if(a==-1) continue;
        ans += dist[a][1];
    }
    cout << ans << endl;
}

