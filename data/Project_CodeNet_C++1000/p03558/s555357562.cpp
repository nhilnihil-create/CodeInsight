#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back
#define INF (1e9+1)

//verified AOJ GRL_1
#define MAX_V 100000
struct edge{int to,cost;};

void dijkstra(int s, vector<int> &d, vector<edge> G[MAX_V]){
    priority_queue< pii,vector<pii>,greater<pii> > que;
    rep( i,d.size() )d[i]=INF;
    d[s] = 0;
    que.push( pii(0,s) );
    
    while( que.size() ){
        pii p=que.top();
        que.pop();
        
        int v=p.second;
        if(d[v]<p.first)continue;
        
        rep(i,G[v].size()){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(pii(d[e.to],e.to));
            }
        }
    }
}

int main(){
    int k;
    cin>>k;
    if(k==1){
        cout<<1<<endl;
        return 0;
    }
    
    vector<edge> G[MAX_V];
    for(int i=1;i<k;i++){
        G[i].pb(edge{(i+1)%k,1});
        G[i].pb(edge{(i*10)%k,0});
    }
    
    vector<int> d(MAX_V);
    dijkstra(1,d,G);
    cout<<d[0]+1<<endl;
}
