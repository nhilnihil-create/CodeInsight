#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
#define big 998244353
#define ff first
#define se second
#define pb push_back
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define PSET(x,y) fixed<<setprecision(y)<<x
#define mp make_pair
#define pi 3.141592653589
int power(int x,int y){
    int r=1,z=x;
    while(y){
        if(y & 1)r*=z;
        z*=z;y=y>>1;}
    return r;}
int powerm(int x,int y,int p){
    int r=1;
    while(y){
        if(y & 1)r=(r*x)%p;
        y=y>>1;
        x=(x*x)%p;}
    return r%p;}
int modinv(int x,int m){
    return powerm(x,m-2,m);}
int logarithm(int a,int b){
    int x=0;
    while(a>1){
        x++;
        a/=b;}
    return x;}
vector<int> ad[100005],ad1[100005];
int vis[100005],dp[100005];
vector<int> topo;
void dfs(int x){
    vis[x]=1;
    for(auto p:ad[x])
        if(!vis[p])
            dfs(p);
    topo.pb(x);
}
int solve(int i){
    if((int)ad1[i].size()==0)
        return dp[i]=0;
    if(dp[i]!=-1)
        return dp[i];
    for(auto p:ad1[i])
        dp[i]=max(dp[i],solve(p)+1);
    return dp[i];
}
int32_t main(){
    fast;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        ad[u].pb(v);
        ad1[v].pb(u);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs(i);
    memset(dp,-1,sizeof(dp));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        int t=topo[i];
        if(dp[t]==-1)
            dp[t]=max(dp[t],solve(t));
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}