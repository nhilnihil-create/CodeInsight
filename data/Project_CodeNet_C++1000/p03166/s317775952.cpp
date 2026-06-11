#include<bits/stdc++.h>
//#include<boost/multiprecision/cpp_ll.hpp>
//using boost::multiprecision::cpp_ll; // use cpp_ll as data type for large numbers 
using namespace std;

#define int ll
#define ll long long
#define pb push_back
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define vi vector<ll>
#define vll vector<long long>
#define log2(X) (63ll - __builtin_clzll(X))
#define test ll t; cin>>t; while(t--)
#define modInv(n) po(n,mod-2)%mod
#define ncr(n,r) (((fact[n]*modInv(fact[r]))%mod)*modInv(fact[n-r]))%mod

ll po(ll a, ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
        {
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b=b/2;
    }
    return res%mod;
}

vll adj[100005+5];
int visited[100005];
ll n,m;
ll ans[100005];
int c;
int dfs(int i)
{
    if(visited[i]) return ans[i];
    
    int c=0;
    visited[i]=1;
    for(auto v: adj[i])
    {
        
        c=max(c,dfs(v)+1);
    }
    return ans[i]=c;
}

signed main() 
{
    fast()
    //test
    {
        cin>>n>>m;
        while(m--)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            //adj[v].pb(u);
        }
        /*for(int i=1; i<=n; i++)
        {
            c=0;
            int res=dfs(i);
            ans[i]=res;
            memset(visited,0,sizeof(visited));
        }*/
        ll ass=INT_MIN;
        for(int i=1;i<=n; i++)  ass=max(ass,dfs(i));
        
        cout<<ass<<"\n";
    }   
}
