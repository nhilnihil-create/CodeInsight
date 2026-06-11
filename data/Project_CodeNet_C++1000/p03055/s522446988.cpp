#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
struct edge{
    ll to,cost;
};
V<edge> graph[200005];
V<ll> dist;
void dfs1(int now,int par){
    for(edge &e:graph[now]){
        if(e.to==par)continue;
        dfs1(e.to,now);
        chmax(dist[now],dist[e.to]+e.cost);
    }
}
ll dfs2(int now,int d_par,int par){
    V<P> dc;
    dc.emplace_back(0,-1);
    for(edge &e:graph[now]){
        if(e.to==par)dc.emplace_back(d_par+e.cost,e.to);
        else dc.emplace_back(e.cost+dist[e.to],e.to);
    }
    sort(all(dc),greater<P>());
    ll res=dc[0].fi+dc[1].fi;
    for(edge &e:graph[now]){
        if(e.to==par)continue;
        chmax(res,dfs2(e.to,dc[dc[0].se==e.to].fi,now));
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    dist.assign(n,0);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        graph[a].emplace_back(edge{b,1});
        graph[b].emplace_back(edge{a,1});
    }
    if(n==1){
        cout<<"First"<<"\n";
        return 0;
    }
    dfs1(n/2,-1);
    ll ma=dfs2(n/2,0,-1);
    ma--;
    if(ma%3==0)cout<<"Second"<<"\n";
    else cout<<"First"<<"\n";
}