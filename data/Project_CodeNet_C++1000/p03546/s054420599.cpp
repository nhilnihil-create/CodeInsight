#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;

struct edge{ll to; ll cost;};
ll V;
vector<ll> d;
vector<vector<edge>> G;

void dijkstra(ll s){
    priority_queue<P,vector<P>,greater<P>> que;
    d = vector<ll>(V,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
        P p = que.top();que.pop();
        ll v = p.second;
        if(d[v]<p.first)continue;
        for(edge e:G[v]){
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll h,w;cin>>h>>w;
    V=10;G=vector<vector<edge>>(10);
    rep(i,10){
        rep(j,10){
            ll c;cin>>c;
            G[j].push_back({i,c});
        }
    }
    dijkstra(1);
    ll ans = 0;
    rep(i,h)rep(j,w){
        ll a;cin>>a;
        if(a==-1)continue;
        ans += d[a];
    }
    cout<<ans<<endl;
    return 0;
}