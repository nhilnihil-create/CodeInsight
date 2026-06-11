#include<bits/stdc++.h>
#define nguyendz the_best

#define all(n) n.begin(),n.end()
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define pll pair<ll,ll>
#define YES cout <<"YES"<<endl;
#define NO cout <<"NO"<<endl;
#define ff first
#define ss second
//#define ((x|y)-y) (x&(~y))
//#define gcd(fibo(x),fibo(y)) = fibo(gcd(x,y))
using namespace std;
const ll maxn=3e3+10;
const ll maxx=1e13;
const ll mod=1e9+7;
const ll mod1=998244353;

vector <pll> adj[maxn];
set<ll> adj1[maxn];
//vector<ll> ans;
//bool kt[maxn];
ll a[maxn];
ll b[maxn] ;
pll p[maxn];

ll dp[maxn][maxn]  ;
ll f[maxn];
int main()
{
    // freopen("test.txt","r",stdin);
    // freopen("CHEMIST.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    string s;
    cin>>n;
    cin>>s;
    for (int i=1;i<=n;i++)
    {
        dp[1][i]=1;

    }
     f[0]=0;

     for (int j=1;j<=n;j++)
        {
            f[j]=(f[j-1]+dp[1][j])%mod ;
        }
    for (int i=2;i<=n;i++)
    {
       for (int j=1;j<=i;j++)
       {
           if (s[i-2]=='<')
           {
               dp[i][j]=f[j-1];
           }
           else
           {
               dp[i][j]=(f[i-1]-f[j-1]+mod*mod )%mod ;
           }
       }
       f[0]=0;
       for (int j=1;j<=n;j++)
        {
            f[j]=(f[j-1]+dp[i][j])%mod ;
        }
    }
    ll ans=0;
    for (int i=1;i<=n;i++)
    {
        ans=(ans+dp[n][i])%mod ;
    }
    cout <<ans;
    return 0;

}
