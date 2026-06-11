#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mp make_pair
#define pb(x) push_back(x)
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pcc pair<char, char>
#define pdd pair<double, double>
#define mll map<long long, long long>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define flsh fflush(stdout)
#define gcd __gcd
#define clr(x) memset(x, 0, sizeof(x))
#define mod 1000000007LL
#define mod2 998244353LL
#define INF 1000000000007
 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> o_tree;


// void solve()
// {
//     string s;
//     cin>>s;
//     ll x1=s[0]-'a';
//     ll x2=s[1]-'a';
//     ll x3=s[2]-'a';
//     ll x4=s[3]-'a';
//     ll f1=0,f2=0;

     
    
    
// }
const int N=1e5+5;
vector<ll> v[N];
ll vis[N];
ll ans[N];
ll noc=0;


void dfs(ll x,ll s)
{
    vis[x]=1;

    for(auto it:v[x])
    {
        if(!vis[it])
        {
            dfs(it,x);
        }
    }
}



void solve()
{
    ll n;
    cin>>n;
    ll u,vv,dis;
    ll i,j;
    clr(ans);
    ll m;
    cin>>m;
    
    for(i=0;i<m;i++)
    {
        cin>>u>>vv>>dis;
        u--,vv--;
        v[u].pb(vv);
        v[vv].pb(u);
    }
    // ll lef=-1;

    for(i=0;i<n;i++)
    {
        if(!vis[i])
        {
            noc++;
            dfs(i,-1);
        }
    }
    cout<<noc<<"\n";

   
  
     
    
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);


if (fopen("input.txt","r" ))
  {
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
  }
cout<<setprecision(20);


ll t=1;


// cin>>t;


while(t--)
{
solve();
} 


return 0;
}