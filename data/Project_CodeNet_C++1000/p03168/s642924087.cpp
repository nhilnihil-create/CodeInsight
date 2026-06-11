#include <bits/stdc++.h>
using namespace std;

#define forn(i,m,n) for(int i=m;i<n;i++)
#define vv vector
#define vi vv<int>
#define ii pair<int,int>
#define vii vv<ii>
#define mp make_pair
#define pb push_back
#define PI 3.141592653589
#define ll long long
#define pll pair<ll,ll>
#define vl vv<ll>
#define ff first
#define ss second
#define MOD 1000000007

bool is_prime[1000001];
vi prime;
void sieve(int n)
{
    memset(is_prime,true,sizeof(is_prime));
    for(int i=2;i*i<=n;i++)
    {
        if(is_prime[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                is_prime[j]=false;
            }
        }
    }
    forn(i,2,n+1)
    {
        if(is_prime[i])
            prime.pb(i);
    }
}


ll ex(ll a,ll b)
{
    ll res=1;
    a=a%MOD;
    while(b)
    {
        if(b%2){res=(res*a)%MOD;b--;}
        b/=2;
        a=(a*a)%MOD;
    }
    return res;
}

ll fermat_inv(ll a){ return ex(a,MOD-2); }
ll max(ll a,ll b){ return a>b?a:b; }
ll min(ll a,ll b){ return a<b?a:b; }


int main()
{
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif
    //sieve(1000000);
    int te=1;
    //cin>>te;
    while(te--)
    {
        int n;
        cin>>n;
        double a[n+1];
        forn(i,1,n+1)
            cin>>a[i];
        double dp[n+1][n+1];
        dp[0][0]=1.0;
        forn(i,1,n+1)
        {
            dp[i][i]=dp[i-1][i-1]*a[i];
            for(int j=i-1;j>=0;j--)
            {
                dp[i][j]=dp[i-1][j]*(1-a[i]);
                if(j>0)
                    dp[i][j]+=dp[i-1][j-1]*a[i];
            }
        }
        double ans=0.0;
        forn(i,n/2+1,n+1)
            ans+=dp[n][i];
        cout<<setprecision(10)<<ans;
    }
}
