#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define PI 3.14159265
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 300000000000000001
#define infx 9223372036854775806
#define all(c) c.begin(),c.end()
#define mk(x,yy) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define ff first
#define ss second
#define re return
// #define endl "\n"
#define max2(x,y)           (x>y)?x:y
#define min2(x,y)           (x<y)?x:y
#define mid(s,e)               (s+(e-s)/2)
#define mini                   INT_MIN
#define maxo                   INT_MAX
#define rep(i,a,b) for(int i=a;i<(int)(b);++i)
#define read(a,n) for(int i=0;i<n;i++)cin>>a[i]
#define show(a,n) for(int i=0;i<n;i++)cout<<a[i]<<' ';cout<<endl
#define ene cout<<"\n";

ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
}
ll power(ll x,  ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 
 
bool compr(std::vector<ll> a, std::vector<ll> b)
{
    if(a[0]==b[0])
        return a[1]<b[1];
    else
        return a[0]<b[0];
}

bool comp(std::vector<ll> a, std::vector<ll> b)
{
    if(a[1]==b[1]&&a[2]==b[2])
        return a[0]<b[0];
    else if(a[1]==b[1])
        return a[2]>b[2];
    else
        return a[1]<b[1];
}

vector<ll> dfs(vector<ll> adj[], ll x, ll visited[])
{
    visited[x] = 1;
    vector<ll> tmp;
    ll black = 1;
    ll white = 1;
    for(ll i=0;i<adj[x].size();i++)
    {
        if(visited[adj[x][i]]==0)
        {
            vector<ll> v = dfs(adj,adj[x][i], visited);
            black = (black*v[0])%mod;
            white = (white*(v[0]+v[1]))%mod;
        }
    }
    tmp.push_back(white);
    tmp.push_back(black);
    return tmp;
}
int main()
{
    #ifdef SHIVANSH 
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> adj[n];
    for(ll i=0;i<n-1;i++)
    {
        ll x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll visited[n] = {};
    vector<ll> v = dfs(adj,0,visited);
    cout<<(v[0]+v[1])%mod<<endl;
}