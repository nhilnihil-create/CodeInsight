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
const ll N=105,M=100005;
ll n,k;
ll a[N];
ll dp[N][M];
ll pre[N][M];
ll dp1[N][M];

void solve()
{
   cin>>n>>k;
   f(i,1,n+1)cin>>a[i];
   
   rep(i,n+1)dp[i][0]=1;
   rep(i,n+1)
   {
       pre[i][0]=dp[i][0];
   }
   f(j,1,k+1)
   {
       pre[0][j]=dp[0][j]%mod+pre[0][j-1]%mod;
       pre[0][j]%=mod;
   }
   f(i,1,n+1)
   {
       f(j,1,k+1)
       {
           ll x=min(a[i],j);
           ll sum=pre[i-1][j]%mod;
           if(j-x-1>=0)
           sum=sum%mod-pre[i-1][j-x-1]%mod+mod;
           sum%=mod;
           dp[i][j]=dp[i][j]%mod+sum%mod;
           dp[i][j]%=mod;
       }
       f(j,1,k+1)
       {
           pre[i][j]=pre[i][j-1]%mod+dp[i][j]%mod;
           pre[i][j]%=mod;
       }
   }

   cout<<dp[n][k];
   
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
