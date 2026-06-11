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

const int MAX_V=10;//最大頂点数
const int INF=1e9;
struct Edge{
    int to;
    int cost;
    Edge(int to,int cost):to(to),cost(cost){}
};
vector<Edge> G[MAX_V];
vector<int> d;
//戻り値がtrueなら負の閉路を含む
bool bellman_ford(int n,int s){//頂点数と開始頂点
    d=vector<int>(n,INF);
    d[s]=0;
    rep(i,n){
        rep(v,n){
            rep(k,G[v].size()){
                Edge e=G[v][k];
                if(d[v]!=INF && d[e.to]>d[v]+e.cost){
                    d[e.to]=d[v]+e.cost;
                    if(i==n-1)return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int H,W;
    cin>>H>>W;
    rep(i,10)rep(j,10){
        int c;
        cin>>c;
        G[j].pb(Edge(i,c));
    }
    bellman_ford(10,1);
    int ans=0;
    rep(i,H)rep(j,W){
        int a;
        cin>>a;
        if(a>=0){ans+=d[a];}
    }
/*rep(i,10){cout<<d[i]<<" ";}
cout<<endl;*/
    cout<<ans<<endl;
}