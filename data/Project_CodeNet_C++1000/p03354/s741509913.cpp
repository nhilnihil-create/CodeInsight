#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ld long double
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

using namespace std;

/* Some Libraries */

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vi p(n);
    rep(i,n) cin>>p[i];
    vector<vi> adj(n);
    rep(i,m){
        int x,y; cin>>x>>y; x--; y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<bool> visit(n,false);
    int ans=0;
    rep(i,n){
        if (visit[i]) continue;
        set<int> s1,s2;
        queue<int> que;
        que.push(i);
        while(que.size()){
            int v=que.front(); que.pop();
            visit[v] = true;
            s1.ins(v);
            s2.ins(p[v]);
            for(auto u:adj[v]){
                if (visit[u]) continue;
                que.push(u);
            }
        }
        for(auto e:s1){
            if (s2.count(e+1)) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
