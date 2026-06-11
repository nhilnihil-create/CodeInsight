#include <bits/stdc++.h>
using namespace std;

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define f           first
#define s          second
#define sz(x)       (int)x.size()
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rep0(a,n)  for(int i=0;i<n;i++)cin>>a[i]
#define si(x)       cin>>x
#define sii(x,y)    cin>>x>>y
#define siii(x,y,z) cin>>x>>y>>z
#define ahell   998244353
#define hell 1000000007
#define N 1000001
#define fl 1.0000000000
//#define mod 998244353
#define cntbit(a) __builtin_popcountl(a)
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
vector<int>adj[100005];
int indeg[100005],lpath[100005];
main()
{
  ios
int n,m,i;
int j;
int u,v,q;
int test=1;
//si(test);

while(test--)
{
  cin>>n;
  double p[n];
  for(i=0;i<n;i++)
    cin>>p[i];

double dp[n+1][n+1];

for(i=0;i<=n;i++)
    for(j=0;j<=n;j++)
        dp[i][j]=0.00;

  dp[0][0]=1.00-p[0];
  dp[0][1]=p[0];

  for(i=1;i<n;i++)
    {
        for(j=0;j<=i+1;j++)
        {
            if(j==0)dp[i][j]=dp[i-1][j]*(1.00-p[i]);
            else
            dp[i][j]=dp[i-1][j]*(1.00-p[i])+dp[i-1][j-1]*(p[i]);
        }
    }

    double ans=0.00;
    for(i=n/2+1;i<=n;i++)
        {//cout<<dp[n-1][i]<<" ";
            ans+=(dp[n-1][i]);
        }

    cout<<setprecision(20)<<ans;

}

}
