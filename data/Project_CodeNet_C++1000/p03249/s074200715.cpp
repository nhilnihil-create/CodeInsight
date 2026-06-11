//kmcode
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
int n;
vector<ll> d;
vector<int> v[100002];
map<ll,int> ret;
int siz[100002];
bool vis[100002];
ll dp[100002];
int cnt[100002];
inline void die(){
    puts("-1");
    exit(0);
}
inline void dfs(int b,int pr=-1){
    cnt[b]++;
    vis[b]=1;
    for(int i=0;i<v[b].size();i++){
        int go=v[b][i];
        if(go==pr) continue;
        if(vis[go])
            die();
        dfs(go,b);
        dp[b]+=dp[go]+cnt[go];
        cnt[b]+=cnt[go];
    }
}
ll ans[100001];
inline void dfs2(int b,int pr=-1,ll weight=0){
    ans[b]=dp[b]+weight;
    weight+=dp[b];
    for(int i=0;i<v[b].size();i++){
        int go=v[b][i];
        if(go==pr) continue;
        dfs2(go,b,weight-dp[go]-cnt[go]+(n-cnt[go]));
    }
}
vector<pii> ed;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        d.pb(a);
        ret[a]=i;
    }
    for(auto it=ret.rbegin();it!=ret.rend();it++){
        int node=(*it).se;
        ll val=(*it).fi;
        siz[node]++;
        ll op=n-siz[node];
        if(op==0) continue;
        ll nex=val+siz[node]-op;
        if(!ret.count(nex))
            die();
        int ne=ret[nex];
        siz[ne]+=siz[node];
        v[ne].pb(node);
        v[node].pb(ne);
        ed.pb(mp(ne+1,node+1));
    }
    dfs(0);
    dfs2(0);
    for(int i=0;i<n;i++){
        if(vis[i]==0)
            die();
        if(ans[i]!=d[i])
            die();
    }
    for(int i=0;i<ed.size();i++)
        cout<<ed[i].fi<<" "<<ed[i].se<<endl;
    return 0;
}