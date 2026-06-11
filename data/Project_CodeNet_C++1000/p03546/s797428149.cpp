#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007;

//Pは<最短距離、頂点番号>。距離のオーダーがllならP pair<ll,int>に変える
#define INF 1e+9//llなら1e18くらい
#define MAX_V 10//最大頂点数
struct Edge{
    int to;
    int cost;
};
int V;//頂点数。main関数で入力
vector<Edge> G[MAX_V];//グラフ。main関数で入力
int d[MAX_V];//最短距離格納用
void dijkstra(int s){//sは始点
    priority_queue<P,vector<P>,greater<P>> que;
    fill(d,d+V,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
        P p=que.top();
        que.pop();
        int v=p.second;
        if(d[v]<p.first)continue;
        for(int i=0;i<G[v].size();i++){
            Edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

int main() {
    int H,W;
    cin>>H>>W;
    rep(i,10){
        rep(j,10){
            int a;
            cin>>a;
            Edge e={i,a};
            G[j].pb(e);
        }
    }
    V=10;
    dijkstra(1);
    int ans=0;
    rep(i,H)rep(j,W){
        int A;
        cin>>A;
        if(A>=0){ans+=d[A];}
    }
    cout<<ans<<endl;
}