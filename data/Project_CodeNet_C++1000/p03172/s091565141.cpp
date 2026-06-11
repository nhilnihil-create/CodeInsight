//clear adj and visited vector declared globally after each test case
//check for long long overflow
//while adding and subs check if mod becomes -ve
//while using an integer directly in a builtin function add ll
//Mod wale question mein last mein if dalo ie. Ans<0 then ans+=mod;
//Dont keep array name as size or any other key word

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);cout.precision(dbl::max_digits10);
#define pb push_back
#define mod 1000000007 //998244353
#define lld long double
#define mii map<int, int>
#define mci map<char, int>
#define msi map<string, int>
#define pii pair<int, int>
#define ff first
#define ss second 
#define all(x) (x).begin(), (x).end()
#define rep(i,x,y) for(int i=x; i<y; i++)    
#define fill(a,b) memset(a, b, sizeof(a))
#define vi vector<int>
#define setbits(x) __builtin_popcountll(x)
#define print2d(dp,n,m) for(int i=0;i<=n;i++){for(int j=0;j<=m;j++)cout<<dp[i][j]<<" ";cout<<"\n";}
typedef std::numeric_limits< double > dbl;
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const long long N=100005, INF=2000000000000000000;
lld pi=3.1415926535897932;
int lcm(int a, int b)
{
    int g=__gcd(a, b);
    return a/g*b;
}
int power(int a, int b, int p)
    {
        if(a==0)
        return 0;
        int res=1;
        a%=p;
        while(b>0)
        {
            if(b&1)
            res=(res*a)%p;
            b>>=1;
            a=(a*a)%p;
        }
        return res;
    }

int dp[101][N];
int32_t main()
{
    IOS;
    int n,k;
    cin>>n>>k;
    int ar[n+1];
    for(int i=1;i<=n;i++)
    cin>>ar[i];
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        dp[i-1][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
        for(int j=0;j<=k;j++)
        {
            dp[i][j]=dp[i-1][j];
            if((j-ar[i]-1)>=0)
            dp[i][j]=(dp[i][j]-dp[i-1][j-ar[i]-1]+mod)%mod;
        }
    }
    cout<<dp[n][k];
}