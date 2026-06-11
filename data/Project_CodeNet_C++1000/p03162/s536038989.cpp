// author -> LetsGoAC
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using    namespace std;
using    namespace __gnu_pbds; 
#define  ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
//  ordered_set os;
//  order_of_key (k) : Number of items strictly smaller than k .
//  *find_by_order(k) : K-th element in a set (counting from zero).
typedef  long double ld;
#define  int long long
typedef  pair<int,int> pii;
#define  RAGE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  rep(i,n) for(i=0; i <n; i++)
#define  repv(i,k,n) for(int i=k; i<=n; i++)
#define  pb push_back
#define  mp make_pair
#define  F  first
#define  S  second
#define  sz(x)  (int)x.size()
#define  all(v) v.begin(),v.end()
#define  endl '\n'
#define  deb(x) cout<<#x<<" = "<<x<<endl
#define  gcd   __gcd
#define  inf   LLONG_MAX
#define  minf  LLONG_MIN 
#define  gi  greater<int> 
#define  gpi greater<pii>  
#define  sp(n) fixed<<setprecision(n)
#define  nl cout<<endl
vector   <int> Fact(1000005 , 0);
const int mod = (int)(1e9+7);
int power(int x,int n)
{   
    if(n==0)    return 1;
    if(n==1)    return x%mod;
    if(n%2==0)  {   int y = power(x,n/2)%mod;return (y*y)%mod;}
    if(n&1)     {   int y = power(x,n-1);return (x%mod * y%mod)%mod;}
    return 0;
}
int modi(int n , int m)
{   //mod = m; // change const mod;
    int mod_inverse = power(n , m-2);
    return mod_inverse;
}
int  pct(int x){return __builtin_popcountll(x);}
int  lcm(int a,int b){return a*b/gcd(a,b);}
bool is_power_2(int n){ return log2(n)==floor(log2(n));}
bool is_prime(int n){if(n<=1)return 0;for(int i=2; i*i<=n; i++)if(n%i==0)return 0; return 1;}
void cal_fac()
{
     Fact[0] = Fact[1] = 1;
     for(int i=2; i<=1000000; i++)
         Fact[i] = (Fact[i-1]*i)%mod;
}
int C(int n , int k)
{
    int res = Fact[n];
    res = (res * modi( Fact[k] , mod ))%mod;
    res = (res * modi( Fact[n-k] ,mod ))%mod;
    return res;
}
ld log(ld n , int base)
{
    ld ans = 1.0 * log(n)/log(base);
    return ans;
}
void db()
{       
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
void timeit()
{  
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed: " <<sp(10)<< 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}
int     dx []    =  {-1 , 0 , 1 , 0 ,-1,-1, 1,  1};
int     dy []    =  { 0 , 1 , 0 ,-1 ,-1, 1, 1, -1};
char    dir[]    =  {'U','R','D','L'};
/* ---------------------- ar.cpp --------------------------------- */
const int maxn = 1e6+5;
void solve(int tc)
{
    //  cout<<"Case #"<<tc<<": ";
    int n,i,j,k,m,q,l,r;
    cin>>n;
    int dp[n][3];
    memset(dp , 0, sizeof(dp));
    rep(i,n)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(!i)
            dp[i][0] = a , dp[i][1] = b , dp[i][2] = c;
        else
        {
            dp[i][0] = max(dp[i-1][1] , dp[i-1][2]) + a;
            dp[i][1] = max(dp[i-1][0] , dp[i-1][2]) + b;
            dp[i][2] = max(dp[i-1][0] , dp[i-1][1]) + c;
        }
    }
    cout<<max({dp[n-1][0] , dp[n-1][1] , dp[n-1][2]});
}   
signed main()   
{
    // ar.cpp
    RAGE;
   // db();
    int t=1;
    // cin>>t;
    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
   // timeit();
    return 0;
}
/*
    1. To find 2's complement , inverse all the bits after 1st set bit. (right -> left
    2. continue , break;
*/  