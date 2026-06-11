/*
 KMP
 */

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("Ofast")

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
typedef pair <int, int> pii;
typedef pair <db, db> pdd;
typedef vector<int> vi;


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
#define all(x) x.begin(),x.end()

inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p%m*p%m)%m;if(n%2) return (p%m*a%m)%m;else return p;}

const ll MOD =998244353;
const ll hell=1000000007;
const int INF=1e15;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
template<typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 rng(seed);

const int N=3005;

int dp[N][N],pre[N][N];

void solve()
{
    
    
    int n;
    cin>>n;
    string s;
    cin>>s;
    dp[1][1]=1;
    pre[1][0]=0;
    pre[1][1]=1;
    for(int i=2;i<=n;i++)
        pre[1][i]=1;
    for(int i=2;i<=n;i++)
    {
        
        if(s[i-2]=='<')
        {
            for(int j=2;j<=i;j++)
            {
                dp[i][j]=(pre[i-1][j-1]-pre[i-1][0]+hell)%hell;
            }
        }
        else
        {
            for(int j=1;j<i;j++)
            {
                dp[i][j]=(pre[i-1][i-1]-pre[i-1][j-1]+hell)%hell;
            }
        }
        for(int j=1;j<=n;j++)
            pre[i][j]=dp[i][j]+pre[i][j-1];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+dp[n][i])%hell;
    cout<<ans<<endl;
    
}


int32_t main()
{
    
    IOS;
   
    //FILE *fin = freopen("in","r",stdin);
    //FILE *fout = freopen("out","w",stdout);
    int t;
    t=1;
   // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

