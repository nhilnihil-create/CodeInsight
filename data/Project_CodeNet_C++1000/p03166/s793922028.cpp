/*
    Author: aksayushx
*/
#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define all(a) a.begin(),a.end()
#define mp make_pair
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef long double ld;

/*
void compute()
{
	fac[0]=1;
	for(ll i=1;i<=10000;i++)
	fac[i]=(i*fac[i-1])%mod;
}
ll power(ll x, ll y)  
{  
    ll res = 1; 
    x = x % mod;
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % mod;  
        y = y>>1; 
        x = (x*x) % mod;  
    }  
    return res;  
} 
ll modInverse(ll n) 
{ 
    return power(n, mod-2); 
}
ll nCr(ll n,ll r) 
{ 
    if (r == 0) 
        return 1; 
    return (fac[n] * modInverse(fac[r]) % mod * modInverse(fac[n - r]) % mod) % mod; 
}*/ 
ll n,m;
vector<vector<ll>> adj;
vector<ll> d;
vector<bool> visited;
ll dfs(ll x)
{
    visited[x]=true;
    if(d[x]!=-1)
    return d[x];
    ll depth=0;
    for(auto c:adj[x])
    {
        if(!visited[c])
        depth=max(depth,1+dfs(c));
        else
        depth=max(depth,1+d[c]);
    }
    d[x]=depth;
    return d[x];
}
void aksayushx()
{
    cin>>n>>m;
    adj.assign(n+1,vector<ll>(0));
    ll x,y;
    visited.assign(n+1,false);
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].pb(y);
    }
    d.assign(n+1,-1);
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        if(!visited[i])
        ans=max(ans,dfs(i));
    }
    cout<<ans;
    

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test=1;
    //cin>>test;
    while(test--)
        aksayushx();
    return 0;
}
