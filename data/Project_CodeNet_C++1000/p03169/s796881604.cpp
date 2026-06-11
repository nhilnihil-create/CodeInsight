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
const int INF = 1e8;
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

ldb dp[301][301][301];int n;

ldb solve(int i,int j,int k)
{
 if(i==0&&j==0&&k==0)
 return dp[i][j][k]=0;

if(dp[i][j][k]!= -1)
return dp[i][j][k];

dp[i][j][k]=1;
if(i)
{
    dp[i][j][k]+=((ldb)i/n)*solve(i-1,j,k);
}
if(j)
{
    dp[i][j][k]+=((ldb)j/n)*solve(i+1,j-1,k);
}
if(k)
{
    dp[i][j][k]+=((ldb)k/n)*solve(i,j+1,k-1);
}
dp[i][j][k]*=n;
dp[i][j][k]/=(i+j+k);
return dp[i][j][k];



}





void solve()
{

for(int i=0;i<=300;i++)
for(int j=0;j<=300;j++)
for(int k=0;k<=300;k++)
dp[i][j][k] = -1;
cin>>n;
int cnt[4]={0};
int x;
for(int i=0;i<n;i++)
{
    cin>>x;
    cnt[x]++;
}
cout<<setprecision(15);
cout<<solve(cnt[1],cnt[2],cnt[3])<<endl;
//cout<<dp[1][0][0]<<" "<<dp[2][0][0]<<endl;








}

int32_t main()
{
    IOS;
    int t;
    t=1;
    //cin>>t;
    while(t--)
    {
        
        solve();
    }
    return 0;
}