#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod=1000000007;
const ll INF=1e15;
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
struct edge{ ll to; ll cap; ll rev;};

const ll MAXN=203;
vector<edge> G[MAXN];

bool used[MAXN];
ll yaku(ll a, ll b){
    if(a>b) return yaku(b,a);
    else{
        if(b%a==0) return a;
        else return yaku(b%a,a);
    }
}

void addEdge0(ll from, ll to, ll cap){
    edge A={to,cap,(ll)G[to].size()};
    edge B={from,0,(ll)G[from].size()};
    G[from].push_back(A);
    G[to].push_back(B);
    return;
}//有向グラフを作る

void addEdge1(ll a, ll b, ll cap){
    edge A={b,cap,(ll)G[b].size()};
    edge B={a,cap,(ll)G[a].size()};
    G[a].push_back(A);
    G[b].push_back(B);
    return;
}//無向グラフを作る

ll dfs(ll v, ll t, ll f){
    if(v==t) return f;
    used[v]=true;
    rep(i,G[v].size()){
        edge &e=G[v][i];
        if(!used[e.to] && e.cap>0){
            ll d=dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

ll MaxFlow(ll Start, ll Goal){
    ll ans=0;
    while(true){
        rep(i,MAXN) used[i]=false;
        ll P=dfs(Start, Goal, INF);
        if(P==0) break;
        ans+=P;
    }
    return ans;
}

ll a[100][2], b[100][2];


int main(){
    ll N; cin>>N;
    rep(i,N) cin>>a[i][0]>>a[i][1];
    rep(i,N) cin>>b[i][0]>>b[i][1];
    rep(i,N) addEdge0(201,i,1);
    rep(i,N) addEdge0(100+i,202,1);
    rep(i,N) rep(j,N){
        if(a[i][0]<b[j][0] && a[i][1]<b[j][1]) addEdge0(i,j+100,1);
    }
    cout<<MaxFlow(201,202)<<endl;
    
}