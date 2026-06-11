#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ff first
#define ss second
typedef long long ll;
ll power(ll a, ll b){//a^b
    ll res=1;
    a=a%MOD;
    while(b>0){
        if(b&1){res=(res*a)%MOD;b--;}
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
ll fermat_inv(ll y){return power(y,MOD-2);}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
vector <int> adj[100001];
vector <int> dp(100001,0);
vector <bool> vis(100001,false);
void dfs(int u){
    for(int v:adj[u]){
        if(vis[v]==false){
            vis[v]=true;
            dfs(v);
        }
        dp[u]=max(dp[u],dp[v]+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==false){
                vis[i]=true;
                dfs(i);
            }   
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            //cout<<dp[i]<<" ";
            ans=max(ans,dp[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}