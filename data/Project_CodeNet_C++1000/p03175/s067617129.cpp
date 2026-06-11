#pragma optimize("unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
// #include <ext/pb_ds/assoc_container.hpp>
// typedef tree<int,null_type,less<int>,rb_tree_tag,
// tree_order_statistics_node_update> indexed_set;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
#define Max(a,b,c) max(a,max(b,c))
#define Min(a,b,c) min(a,min(b,c))
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define pc(x)  __builtin_popcount (x)
#define vl vector< ll >
#define sorts(v) sort(v.begin(),v.end())
#define sortg(v) sort(v.begin(),v.end(),greater<ll>())
#define ss second
#define ff first
#define ll long long
#define ld long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1e18)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod 1000000007
#define mem(x,y) memset(x,y,sizeof(x))
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define gcd __gcd
#define primeDEN 727999983
#define nx_pe next_permutation(s.begin(),s.end())
#define cl cout<<"\n"
#define sp(x) setprecision(x)
const ll N=1e5+5;
vector<ll>v[N];
ll dp[N][2];
bool vis[N];
ll n;

void dfs(ll u)
{
    vis[u]=1;
    for(ll x:v[u])
    {
        if(vis[x])continue;
        dfs(x);
        dp[u][0]=(dp[u][0]%mod*(dp[x][0]%mod+dp[x][1]%mod+mod)%mod)%mod;
        dp[u][1]=(dp[u][1]%mod*((dp[x][0]%mod+mod)%mod)%mod);
    }
}


void solve()
{
   cin>>n;
   rep(i,n-1)
   {
       ll x,y;
       cin>>x>>y;
       v[x].pb(y);
       v[y].pb(x);
   }
   if(n==1)
   {
       cout<<2<<"\n";
       return ;
   }
   f(i,1,n+1)
   {
       
       {
           dp[i][0]=1;
           dp[i][1]=1;
       }
   }
   dfs(1);
//    f(i,1,n+1)
//    {
//        cout<<i<<"    "<<dp[i][0]<<' '<<dp[i][1]<<"\n";
//    }
   cout<<(dp[1][0]%mod+dp[1][1]%mod+mod)%mod<<"\n";
}


    
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("ouput.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    std::ios::sync_with_stdio(false);
    ll te=1;
    // cin>>te;
    while(te--){
        solve();
    }
    
}
