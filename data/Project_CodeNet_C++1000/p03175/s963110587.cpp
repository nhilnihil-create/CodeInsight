
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
#define int long long int
typedef complex<long double> cd;
const long double pi=acos(-1);
typedef double db;
typedef long double ldb;
typedef pair <int,int> pii;
typedef pair <db,db> pdd;
typedef vector<int> vi;
typedef vector<vector<int> > matrix;
 
#define m1 make_pair
#define pb push_back
#define flush fflush(stdout)
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define reset(x,v) memset(x,v,sizeof(x))
 
#define fi first
#define se second
#define endl "\n"
#define debug(x) (cerr << #x << ": " << x << "\n")
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
 
inline int gcd(int a,int b){if(a==0) return b;return gcd(b%a,a);}
inline int power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p%m*p%m)%m;if(n%2) return (p%m*a%m)%m;else return p;}
const double EPS = 1e-9;
const ll MOD=998244353;
const ll hell=1000000007;
const int INF = 1e16;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
template<typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 rng(seed);
 
double startTime;
double getCurrentTime() {
    return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };
 
const int N=100005;

vi adj[N+1];
int dp[N+1][2];

void dfs(int u,int p)
{
dp[u][0]=1;
dp[u][1]=1;
for(int v:adj[u])
{
    if(v!=p)
    {
        dfs(v,u);
        dp[u][0]=(dp[u][0]*(dp[v][0]+dp[v][1])%hell)%hell;
        dp[u][1]=(dp[u][1]*dp[v][0])%hell;
    }
}



}

    
void solve()
{
int n;
cin>>n;
int u,v;
for(int i=0;i<n-1;i++)
{
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
}
dfs(1,0);
cout<<(dp[1][0]+dp[1][1])%hell<<endl;
}

int32_t main()
{
    //IOS;
    int t;
    t=1;
    //cin>>t;
    while(t--)
    {
        
        solve();
    }
    return 0;
}