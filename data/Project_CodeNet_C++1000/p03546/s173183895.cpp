#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int h,w;
    const int INF = INT32_MAX>>3;
    cin >> h >> w;
    //ベルマンフォード法
    /*
    struct edge {
        int from, to, cost;
    };
    vector<edge> G(9*9);
    rep(i,10) rep(j,10) {
        int c;
        cin >> c;
        if(i == j) continue;
        G.push_back({i,j,c});
    }
    vector<int> A;
    rep(i,h) rep(j,w) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    vector<int> d_min(10);
    rep(i, 10) {
        vector<int> d(10, INF);
        d[i] = 0;
        rep(j, 10) {
            for(auto e: G) {
               if(d[e.from] != INF && d[e.from] + e.cost < d[e.to]){
                   d[e.to] = d[e.from] + e.cost;
               }
            }
        }
        d_min[i] = d[1];
    }
    int ans = 0;
    rep(i, A.size()) {
        if(A[i] != -1) {
            ans+=d_min[A[i]];
        }
    }
    cout << ans << endl;
    */

    //ワーシャルフロイド法
    /*
    vector<vector<int>> d(10,vector<int>(10,INF));
    rep(i,10) rep(j,10) cin >> d[i][j];
    vector<vector<int>> a(h, vector<int>(w));
    rep(i,h) rep(j,w) cin >> a[i][j];
    rep(k,10) rep (i,10) rep(j,10) chmin(d[i][j], d[i][k] + d[k][j]);
    int ans = 0;
    rep(i,h) rep(j,w) if(a[i][j]!=-1)ans+=d[a[i][j]][1];
    cout << ans << endl;
    */
   //ダイクストラ法
    struct edge {
       ll to, cost;
    };
    vector<vector<edge>> G(10);
    rep(i,10) rep(j,10) {
        int c;
        cin  >> c;
        G[i].push_back({j,c});
    }
    vector<int> A;
    rep(i,h*w) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    using P=pair<int,int>;
    vector<int> s_min(10);
    rep(s,10) {
        vector<int> d(10,INF);
        priority_queue<P, vector<P>, greater<P>> pq;
        d[s] = 0;
        pq.emplace(d[s], s);
        while(!pq.empty()) {
            P p = pq.top();
            int v = p.second;
            pq.pop();
            if(p.first > d[v]) continue;
            for(auto e : G[v]) {
                if(p.first + e.cost < d[e.to]) {
                    d[e.to] = p.first + e.cost;
                    pq.emplace(d[e.to], e.to);
                }
            }
        }
        s_min[s] = d[1];
    }
    int ans = 0;
    rep(i,A.size()) {
        if (A[i] == -1) continue;
        ans += s_min[A[i]];
    }
    cout << ans << endl;
}