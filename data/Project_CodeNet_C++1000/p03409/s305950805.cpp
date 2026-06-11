#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define LINF 1e18
#define INF 1e9
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;

const ll MAX_V = 1000;

struct Edge{
    ll rev,from,to;
    ll cap,icap;
    Edge(ll r,ll f,ll t,ll c) : rev(r), from(f), to(t), cap(c), icap(c) {}
};

struct Graph{
    ll V;
    vector<Edge> list[MAX_V];

    Graph(ll n = 0) : V(n) {rep(i,0,MAX_V) list[i].clear();}
    void init(ll n = 0) {V = n; rep(i,0,MAX_V) list[i].clear(); }
    void resize(ll n = 0) {V = n;}
    void reset() { rep(i,0,V) rep(j,0,list[i].size()) list[i][j].cap = list[i][j].icap; }
    inline vector<Edge>& operator[] (ll i) {return list[i]; }

    Edge &redge(Edge e){
        if(e.from != e.to) return list[e.to][e.rev];
        else return list[e.to][e.rev+1];
    }

    void addedge(ll from,ll to,ll cap){
        list[from].push_back(Edge((ll)list[to].size(),from,to,cap));
        list[to].push_back(Edge((ll)list[from].size()-1,to,from,0));
    }
};

static ll level[MAX_V];
static ll iter[MAX_V];

void dibfs(Graph &G,ll s){
    rep(i,0,MAX_V) level[i] = -1;
    level[s] = 0;  
    queue<ll> que;
    que.push(s);
    while(!que.empty()){
        ll v = que.front();
        que.pop();

        rep(i,0,G[v].size()){
            Edge &e = G[v][i];
            if(level[e.to] < 0 && e.cap > 0){
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

ll didfs(Graph &G,ll v,ll t,ll f){
    if(v == t) return f;
    for(ll &i = iter[v];i < G[v].size();i++){
        Edge &e = G[v][i], &re = G.redge(e);
        if(level[v] < level[e.to] && e.cap > 0){
            ll d = didfs(G,e.to,t,min(f,e.cap));
            if(d > 0){
                e.cap -= d;
                re.cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll Dinic(Graph &G, ll s,ll t){
    ll res = 0;
    while(1){
        dibfs(G,s);
        if(level[t] < 0) return res;
        fill(iter,iter+MAX_V,0);
        ll flow;
        while((flow = didfs(G,s,t,LINF)) > 0){
            res += flow;
        }
    }
}

signed main(){
    ll n;
    cin >> n;

    P red[n],blue[n];
    rep(i,0,n) cin >> red[i].fs >> red[i].sc;
    rep(i,0,n) cin >> blue[i].fs >> blue[i].sc;

    Graph G(2*n+2);
    ll S_node = 2*n;
    ll T_node = 2*n+1;

    rep(i,0,n){
        rep(j,0,n){

            if(red[j].fs < blue[i].fs && red[j].sc < blue[i].sc){
                G.addedge(i,n+j,1);
            }
        }
    }

    rep(i,0,n){
        G.addedge(S_node,i,1);
        G.addedge(n+i,T_node,1);
    }

    cout << Dinic(G,S_node,T_node) << endl;
    return 0;
}