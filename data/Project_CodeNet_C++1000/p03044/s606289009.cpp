#include<bits/stdc++.h>
#include<string.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define see(x) cout<<#x<<" : "<<(x)<<endl;
#define ya cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define ff first
#define sc second
typedef long long ll;
using namespace std;
 
const ll N=100009;
ll n,u,vv,w;
vector<ll>v[N],ww[N];
bool vis[N];
ll ans[N];
void dfs(ll i)
{
    vis[i]=1;
    for(ll j=0;j<v[i].size();j++)
    {
        u=v[i][j];
        w=ww[i][j];
        if(!vis[u])
        {
            if(w&1)
            {
                ans[u]=!ans[i];
            }
            else
            {
                ans[u]=ans[i];
            }
            dfs(u);
        }
    }
}
int main()
{
    ll i,j;
    cin >>n;
    for(i=1;i<n;i++)
    {
        cin >> u >> vv >> w;
        v[u].pb(vv);
        v[vv].pb(u);
        ww[u].pb(w);
        ww[vv].pb(w);
    }
    dfs(1);
    for(i=1;i<=n;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}