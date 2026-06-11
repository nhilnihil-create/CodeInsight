#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

#define INF 1e8

using namespace std;

struct edge {
    int to,cost;
    edge(){}
    edge(int to,int cost):to(to),cost(cost){}
};

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll k; cin>>k;
    vector<vector<edge> > adj(k);
    rep(i,k){
        adj[i].pb(edge((i+1)%k,1));
        adj[i].pb(edge((i*10)%k,0));
    }
    priority_queue<pi,vector<pi>,greater<pi> > que;
    que.emplace(0,1);
    vi dist(k,INF);
    dist[1] = 0;
    while(!que.empty()){
        int d,v;
        tie(d,v) = que.top(); que.pop();
        if (d>dist[v]) continue;
        for(auto e:adj[v]){
            if (dist[e.to]>dist[v]+e.cost){
                dist[e.to] = dist[v]+e.cost;
                que.emplace(dist[e.to],e.to);
            }
        }
    }
    cout<<dist[0]+1<<"\n";
    return 0;
}
