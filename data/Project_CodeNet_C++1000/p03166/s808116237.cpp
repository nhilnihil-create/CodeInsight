#include <bits/stdc++.h>
using namespace std;
#include <string.h>
#include <map>
#define MEM(var, val) memset(var, (val), sizeof(var))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define nitro                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
#define mp make_pair
#define pb push_back
#define F first
#define S second
//*max_element(a.begin(), a.end())
vector<vll>adj;
vll vis;
vll d;
void dfs(int v)
{
    if(vis[v])
    return ;
    vis[v]=1;
    for(int i:adj[v])
    {
        if(!vis[i])
        dfs(i);
        d[v]=MAX(d[v],1+d[i]);
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    adj.clear();
    adj.resize(n+1);
    vis.clear();
    vis.resize(n+1,0);
    d.clear();
    d.resize(n+1,0);
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        dfs(i);
    }
    cout<<*max_element(d.begin(),d.end());

}