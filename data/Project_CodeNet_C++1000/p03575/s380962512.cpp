#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define inf LLONG_MAX>>2
#define MAX 1000000
#define mod 1000000007
#define pb push_back
#define f(i,a,n,x) for ((i)=(a);(i)<(n);(i)+=(x))
#define fd(i,a,n,x) for ((i)=(a);(i)>=(n);(i)-=(x))
#define fi first
#define se second
#define mk make_pair
#define pi pair
#define vt vector
using namespace std;
void read(vt<ll> &a,ll n){ll i,temp;f(i,0,n,1){cin>>temp;a.pb(temp);}}
vt<vt<ll>> adj(100);
ll dfs(ll x,vt<vt<ll>> &adj,vt<bool> &visited){
    ll i,ans=1;
    visited[x]=true;
    f(i,0,adj[x].size(),1)
        if (!visited[adj[x][i]])
            ans+=dfs(adj[x][i],adj,visited);
    return ans;
}
void solve(){
    ll n,m,i,j,x,y,temp,ans=0,p;
    cin>>n>>m;
    f(i,0,m,1){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    f(i,1,n+1,1){
        f(j,0,adj[i].size(),1){
            p=adj[i][j];
            adj[i].erase(adj[i].begin()+j);
            vt<bool> visited(100,false);
            temp=dfs(1,adj,visited);
            if (temp<n)
                ans++;
            adj[i].insert(adj[i].begin()+j,p);
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}