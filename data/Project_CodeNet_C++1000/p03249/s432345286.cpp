//tourist
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
map<ll,int> ret;
int n;
inline void die(){
    puts("-1");
    exit(0);
}
int main(){
    cin>>n;
    vector<ll> d(n);
    for(int i=0;i<n;i++){
        cin>>d[i];
        ret[d[i]]=i;
    }
    vector<int> siz(n,1);
    vector<pii> ans;
    for(int i=0;i<n-1;i++){
        auto it=ret.rbegin();
        int now=it->se;
        ll need=d[now]-n+2*siz[now];
        if(!ret.count(need) || ret[need]==now)
            die();
        int par=ret[need];
        ans.pb(mp(now,par));
        siz[par]+=siz[now];
        ret.erase(--ret.end());
    }
    vector<ll> real_dist(n,-1);
    real_dist[0]=0;
    vector<vector<int> > g(n);
    for(int i=0;i<ans.size();i++){
        g[ans[i].fi].pb(ans[i].se);
        g[ans[i].se].pb(ans[i].fi);
    }
    vector<int> que(1,0);//和queue过不去 
    for(int b=0;b<que.size();b++){
        for(int j=0;j<g[que[b]].size();j++){
            if(real_dist[g[que[b]][j]]==-1){
                que.pb(g[que[b]][j]);
                real_dist[g[que[b]][j]]=real_dist[que[b]]+1;
            }
        }
    }
    if(accumulate(real_dist.begin(),real_dist.end(),(ll)0)!=d[0])
        die();
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].fi+1<<" "<<ans[i].se+1<<endl;
    return 0;
}