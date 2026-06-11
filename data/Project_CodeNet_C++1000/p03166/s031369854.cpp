#include <bits/stdc++.h>
using namespace std;

#define     FasterIO        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     bug(a,b)        cout<<a<<"\t"<<b<<"\n";
#define     Case(a,b)       cout<<"Case "<<a<<": "<<b<<"\n";
#define     precision(a,b)  fixed<<setprecision(a)<<b
#define     lp(i,a,b)       for(int i=a;i<b;i++)
#define     Endl            "\n"
#define     tab             "\t"
#define     reset(a,b)      memset(a,b,sizeof(a));
#define     sf(a)           scanf(" %d", &a);
#define     sfl(a)          scanf(" %lld", &a);
#define     srt(a)          sort(a.begin(),a.end());
#define     ALL(a)          a.begin(),a.end()
#define     pb(a)           push_back(a)
#define     pi              2*acos(0.0)

typedef long long int ll;
typedef unsigned long long int ull;

const int sz=1e5+9 , infP=INT_MAX , infN=INT_MIN ,mod=1e9+7, eps=1e-9;


void ini(){

    return;
}

vector<int> g[sz];
int vis[sz],dp[sz],n,m,x,y,ans=0;

void dfs(int u){
    // bug(u,dp[u]);
    vis[u]=1;
    for(auto &v:g[u]){
        if(!vis[v])dfs(v);
        dp[u]=max(dp[u],1+dp[v]);
    }
    // bug(u,dp[u]);
}


void solve(){

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        g[x].pb(y);
    }

    for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
    
    
    for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
    

    cout<<ans<<Endl;

}

int main(){
    FasterIO;
    #ifndef ONLINE_JUDGE
        freopen("input.in","r",stdin);
        freopen("output.in","w",stdout);
    #endif
    // ini();
    int t=1;
    // cin>>t;
    while(t--)
        solve();
}
