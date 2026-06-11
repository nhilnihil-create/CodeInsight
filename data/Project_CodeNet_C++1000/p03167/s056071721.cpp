#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define ld long double
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,a) REP(i,0,a)
#define REV(i,a,b) for(i=a-1;i>=b;i--)
#define rev(s) reverse(s.begin(),s.end())
#define pb push_back
#define mp make_pair
#define ord(v) sort(v.begin(),v.end());
const ll MAXN=1e6+10;
#define MAX 2*1e9
#define fi first
#define se second
#define pi 3.141592653589793238
#define rem 1000000007
#define eps 1e-9
#define endl '\n'
#define lb lower_bound
#define ub upper_bound
#define print(stuff) cout << stuff << endl
#define printc(stuff) for(auto x: stuff) cout << x << " "; cout << endl;
#define printPrec(stuff) cout << fixed << setprecision(15) << stuff << endl;
#define inf 0x3f3f3f3f3f3f3f3f

/*****Some Useful Functions*****/
ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}
ll binpow(ll a,ll b,ll r)
{
    a%=r;
    ll res=1;
    while(b>0)
    {
        if(b&1)
            res=(res*a)%r;
        a=(a*a)%r;
        b>>=1;
    }
    return res;
}
/*****Some Useful Functions*****/

// fflush(stdout);
//lower_bound,upper_bound,equal_range


void raa_j_shh(void);
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
    cout << fixed << setprecision(10);
    ll t=1;
    // cin>>t;
    while(t--) raa_j_shh();    
    return 0;
 } 

/*********El codigo comienza aqui*********/


void raa_j_shh()
{
    ll n,m,i,j;
    cin>>n>>m;
    char a[n][m];
    ll dp[n][m];
    rep(i,n)
    rep(j,m)
    cin>>a[i][j];
    dp[0][0]=1;
    for(i=1;i<n;i++)
    {
        if(a[i][0]=='.')
           { if(dp[i-1][0]==1)
                    dp[i][0]=1;
             else dp[i][0]=0;
            }
        else dp[i][0]=0;
    }
    for(i=1;i<m;i++)
    {
        if(a[0][i]=='.')
           { if(dp[0][i-1]==1)
                    dp[0][i]=1;
             else dp[0][i]=0;
            }
        else dp[0][i]=0;
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
        {
            if(a[i][j]=='.')
               { dp[i][j]=dp[i-1][j]+dp[i][j-1];dp[i][j]%=rem;}
            else dp[i][j]=0;
        }
    }
    cout<<dp[n-1][m-1]%rem<<endl;
   return;
}


/*********El codigo termina aqui**********/ 