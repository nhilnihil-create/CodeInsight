#include<bits/stdc++.h>
using namespace std;
// -----------------<fast IO>------------------
#define IOS             ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FLSH             fflush(stdout)
#define fileIO(name) \
    freopen(name".in", "r", stdin); \
    freopen(name".out", "w", stdout);
#define PRECISION(x)     cout << fixed << setprecision(x);
// -----------------<TypeDef Start>------------------
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
// -----------------<Constants>------------------
const int MAXN = 1000005;
const int SQRTN = 1003;
const int LOGN = 22;
const double PI=acos(-1);

const int INF=1e9;

int MOD = 1000000007;
const int FMOD = 998244353;
const double eps = 1e-9;
/*ll gcd(ll a,ll b)
{
    if(a==0)
    return(b);
    return(gcd(b%a,a));
}*/
// --------------------------------------------------</TEMPLATE>--------------------------------------------------

long double dp[3000][3000];
void solve()
{
    ll n;
    cin>>n;
    long double arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(j==0)
                dp[i][j]=dp[i-1][j]*((long double)1-arr[i-1]);
            else
                dp[i][j]=dp[i-1][j-1]*arr[i-1]+dp[i-1][j]*((long double)1-arr[i-1]);
        }
    }
    long double ans=0;
    for(int i=n/2+1;i<=n;i++)
        ans+=dp[n][i];
    cout<<fixed<<setprecision(10)<<ans<<endl;
}

int main()
{
    IOS
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return(0);
}
