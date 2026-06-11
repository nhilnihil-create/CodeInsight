//clear adj and visited vector declared globally after each test case
//check for long long overflow
//while adding and subs check if mod becomes -ve
//while using an integer directly in a builtin function add ll
//Mod wale question mein last mein if dalo ie. Ans<0 then ans+=mod;
//Dont keep array name as size or any other key word

#include <bits/stdc++.h>
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
#define print2d(prob,n,m) for(int i=0;i<=n;i++){for(int j=0;j<=m;j++)cout<<prob[i][j]<<" ";cout<<"\n";}
typedef std::numeric_limits< double > dbl;
using namespace std;
const long long N=100005, INF=2000000000000000000;
lld pi=3.1415926535897932;
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
lld dp[301][301][301];
int n;

lld solve(int x, int y, int z)
{
    if(x<0||y<0||z<0)
    return 0.0;
    if(x==0&&y==0&&z==0)
    return 0.0;
    if(dp[x][y][z]>0)
    return dp[x][y][z];
    lld den=x+y+z;
    lld ans=n+x*solve(x-1, y, z)+y*solve(x+1, y-1, z)+z*solve(x, y+1, z-1);
    ans/=den;
    return dp[x][y][z]=ans;
}

int32_t main()
{
    IOS;
    cin>>n;
    lld den=(lld)n+0.0;
    int x=0,y=0,z=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a==1)
        x++;
        else if(a==2)
        y++;
        else
        z++;
    }
    cout<<solve(x, y, z);
}
