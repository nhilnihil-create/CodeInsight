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
        int n,m;
        cin>>n>>m;
        ll dp[n][m];
        char ch;
        forn(i,0,n)
        {
            forn(j,0,m)
            {
                cin>>ch;
                if(i==0 && j==0)
                    dp[i][j]=1;
                else
                {
                    if(ch=='.')
                    {
                        dp[i][j]=0;
                        if(j-1>=0 && dp[i][j-1]!=-1)
                            dp[i][j]+=dp[i][j-1];
                        if(i-1>=0 && dp[i-1][j]!=-1)
                            dp[i][j]+=dp[i-1][j];
                        dp[i][j]%=MOD;
                    }
                    else
                        dp[i][j]=-1;
                }
            }
        }
        cout<<dp[n-1][m-1];        
    }
}
